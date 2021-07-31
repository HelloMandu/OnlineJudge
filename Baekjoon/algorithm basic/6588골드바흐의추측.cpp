#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 1000001;

bool isPrime[MAX];

void initPrime(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i = 2; i * i <= MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
}


int main(){
    int n;
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    initPrime();
    while(cin >> n){
        if(n == 0){
            break;
        }
        bool flag = false;
        for(int i = 2; i <= n / 2; i++){
            if(isPrime[i] && isPrime[n - i]){
                cout << n << " = " << i << " + " << n - i << '\n';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}