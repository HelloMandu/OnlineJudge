/**
 * TODO: k range 해결할 것
 */
#include<bits/stdc++.h>
using namespace std;

long long n, k;
int arr[501];
int cache[501];
long long cacheCnt[501];
int lisLength;

const long long MAX = 2000000000 + 1;

int getLis(int cur){
    int &ret = cache[cur + 1];
    if(ret != -1){
        return ret;
    }
    ret = 1;
    for(int i = cur + 1; i < n; i++){
        if(cur == -1 || arr[cur] < arr[i]){
            ret = max(ret, getLis(i) + 1);
        }
    }
    return ret;
}

long long getLisCnt(int cur){
    long long &ret = cacheCnt[cur + 1];
    if(cache[cur + 1] == 1){
        return ret = 1;
    } else if(ret != -1){
        return ret;
    }
    ret = 0;
    for(int i = cur + 1; i < n; i++){
        if(cur == -1 || arr[cur] < arr[i] && cache[cur + 1] == cache[i + 1] + 1){
            ret = min(MAX, ret + getLisCnt(i));
        }
    }
    return ret;
}

void findSequence(int cur, long long skip, vector<int>& lis){
    if(cur != -1){
        lis.push_back(arr[cur]);
    }
    vector<pair<int, int> > nextList;
    for(int i = cur + 1; i < n; i++){
        if((cur == -1 && cache[i + 1] == lisLength) || arr[cur] < arr[i] && cache[cur + 1] == cache[i + 1] + 1){
            nextList.push_back(make_pair(arr[i], i));
        }
    }
    sort(nextList.begin(), nextList.end());
    for(int i = 0; i < nextList.size(); i++){
        int idx = nextList[i].second;
        long long value = cacheCnt[idx];
        if(value < skip){
            skip -= value;
        } else{
            findSequence(idx, skip, lis);
            break;
        }
    }
}

int main(){
    freopen("../input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    while(testcase--){
        memset(cache, -1, sizeof(cache));
        memset(cacheCnt, -1, sizeof(cacheCnt));
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        lisLength = getLis(-1) - 1;
        getLisCnt(-1);
        cout << lisLength << '\n';
        vector<int> lis;
        findSequence(-1, k, lis);
        for(int i = 0; i < lis.size(); i++){
            cout << lis[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}