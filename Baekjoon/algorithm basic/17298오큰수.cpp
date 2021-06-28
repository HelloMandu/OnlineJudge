#include<iostream>
using namespace std;

int arr[1000001];

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]){
                cout << arr[j] << ' ';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << -1 << ' ';
        }
    }
    return 0;
}