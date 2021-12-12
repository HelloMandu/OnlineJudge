#include<bits/stdc++.h>
using namespace std;

int arr[4001][4001];
int result = 0;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int length = max(str1.length(), str2.length());
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= length; j++){
            if(str1[i - 1] == str2[j - 1]){
                arr[i][j] = arr[i - 1][j - 1] + 1;
                result = max(result, arr[i][j]);
            }
        }
    }
    cout << result;
    return 0;
}