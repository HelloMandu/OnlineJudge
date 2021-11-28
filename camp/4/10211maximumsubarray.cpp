#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        int arr[1001] = {0,};
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int result = -1e9;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = max(sum, 0) + arr[i];
            result = max(result, sum);
        }
        cout << result << '\n';
    }
	return 0;
}