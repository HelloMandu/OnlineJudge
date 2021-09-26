#include<bits/stdc++.h>
using namespace std;

int n;
int arr[501];
int lis[501];

int getLis(int cur){
    int& ret = lis[cur + 1];
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

int main() {
	freopen("../input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
        cin >> n;
        memset(lis, -1, sizeof(lis));
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << getLis(-1) - 1 << '\n';
	}
	return 0;
}