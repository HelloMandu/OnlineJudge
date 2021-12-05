#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > graph;
int people[11];
bool isVisit[11];

vector<int> getArr(vector<bool> arr, bool type){
    vector<int> result;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == type){
            result.push_back(i + 1);
        }
    }
    return result;
}

int getSum(vector<int> arr){
    int result = 0;
    for(int i = 0; i < arr.size(); i++){
        result += people[arr[i]];
    }
    return result;
}

bool isInclude(vector<int> arr, int cur){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == cur){
            return true;
        }
    }
    return false;
}

int dfs(int cur, vector<int> arr){
    int result = 0;
    isVisit[cur] = true;
    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];
        if(!isVisit[next] && isInclude(arr, next)){
            result += dfs(next, arr);
        }
    }
    return result + 1;
}

bool isConnected(vector<int> arr){
    if(dfs(arr[0], arr) != arr.size()){
        return false;
    }
    return true;
}
int main(){
    cin >> n;
    graph.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> people[i];
    }
    for(int i = 1; i <= n; i++){
        int edges;
        cin >> edges;
        for(int j = 0; j < edges; j++){
            int e;
            cin >> e;
            graph[i].push_back(e);
            graph[e].push_back(i);
        }
    }
    int result = 987654321;

    for(int i = 1; i <= n / 2; i++){
        vector<bool> arr;
        for (int j = 0; j < i; j++) {
			arr.push_back(false);
		}
		for (int j = 0; j < n - i; j++) {
			arr.push_back(true);
		}
        do{
            memset(isVisit, false, sizeof(isVisit));
            vector<int> a = getArr(arr, false);
            vector<int> b = getArr(arr, true);
            if(isConnected(a) && isConnected(b)){
                result = min(result, abs(getSum(a) - getSum(b)));
            }
        } while(next_permutation(arr.begin(), arr.end()));
    }

    cout << (result == 987654321 ? -1 : result);
    return 0;
}