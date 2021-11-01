#include<bits/stdc++.h>
using namespace std;

int arr[3];
int buttons[3] = {300, 60, 10};

int main(){
    int n;
    cin >> n;
    int result = 0;
    for(int i = 0; i < 3; i++){
        arr[i] = n / buttons[i];
        n %= buttons[i];
    }
    if(n){
        cout << -1;
    } else{
        for(int i = 0; i < 3; i++){
            cout << arr[i] << ' ';
        }
    }
    return 0;
}