#include<iostream>
#include<algorithm>
using namespace std;

long long  dis[100001];
long long  oil[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> dis[i];
    }
    for(int i = 0; i < n; i++){
        cin >> oil[i];
    }
    long long  result = 0;
    long long  minOil = oil[0];
    for(int i = 0; i < n - 1; i++){
        minOil = min(minOil, oil[i]);
        result += minOil * dis[i];
    }
    cout << result;
    return 0;
}