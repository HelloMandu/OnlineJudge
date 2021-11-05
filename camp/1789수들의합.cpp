#include<bits/stdc++.h>
using namespace std;

int main(){
    long long inp;
    cin >> inp;
    long long sum = 0;
    int num = 1;
    int result = 0;
    while(sum < inp){
        sum += num++;
        result++;
    }
    cout << (sum == inp ? result : result - 1);
    return 0;
}