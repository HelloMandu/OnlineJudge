#include<bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        int n;
        vector<int> arr, permutation;
        cin >> n;
        if(!n){
            break;
        }
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        for(int i = 0; i < n; i++){
            permutation.push_back(i >= 6 ? 1 : 0);
        }

        do{
            vector<int> result;
            for(int i = 0; i < n; i++){
                if(!permutation[i]){
                    result.push_back(arr[i]);
                }
            }
            for(int i = 0; i < 6; i++){
                cout << result[i] << ' ';
            }    
            cout << '\n';
        } while(next_permutation(permutation.begin(), permutation.end()));
        cout << '\n'; 
        arr.clear();
        permutation.clear();
    }
    return 0;
}