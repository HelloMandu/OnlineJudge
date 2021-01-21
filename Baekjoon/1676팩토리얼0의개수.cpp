#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    int five = 0, two = 0;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int num = i;
        while(!(num % 5)){
            num /= 5;
            five++;
        }
        while(!(num % 2)){
            num /= 2;
            two++;
        }
    }
    cout << min(five, two);
    return 0;
}