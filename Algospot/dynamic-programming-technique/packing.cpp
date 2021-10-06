#include<bits/stdc++.h>
using namespace std;

struct Package{
    string name;
    int weight, want;
};

int n, w;
vector<Package> allPackages;
vector<Package> packages;
int cache[101][1001];

int solution(int cur, int totalWeight){
    if(cur == n){
        return 0;
    }
    int& ret = cache[cur][totalWeight];
    if(ret != -1){
        return ret;
    }
    ret = solution(cur + 1, totalWeight);
    if(totalWeight >= allPackages[cur].weight){
        ret = max(ret, solution(cur + 1, totalWeight - allPackages[cur].weight) + allPackages[cur].want);
    }
    return ret;
}

void findPackages(int cur, int totalWeight){
    if(cur == n){
        return;
    }
    if(solution(cur, totalWeight) > solution(cur + 1, totalWeight)){
        packages.push_back(allPackages[cur]);
        findPackages(cur + 1, totalWeight - allPackages[cur].weight);
    } else{
        findPackages(cur + 1, totalWeight);
    }
}

int main(){
    freopen("../input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n >> w;
        allPackages.reserve(n);
        memset(cache, -1, sizeof(cache));
        for(int i = 0; i < n; i++){
            Package package;
            cin >> package.name >> package.weight >> package.want;
            allPackages.push_back(package);
        }
        int maxWeight = solution(0, w);
        findPackages(0, w);
        cout <<  maxWeight << ' ' << packages.size() << '\n';
        for(int i = 0; i < packages.size(); i++){
            cout << packages[i].name << '\n';
        }
        packages.clear();
        allPackages.clear();
    }
    return 0;
}