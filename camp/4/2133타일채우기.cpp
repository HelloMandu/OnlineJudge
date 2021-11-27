#include<bits/stdc++.h>
using namespace std;

int cache[31] = {1, 0, 3};

int main(){
	int n;
	cin >> n;
	for(int i = 4; i <= n; i++){
		cache[i] = cache[i - 2] * 3;
		for(int j = 4; i - j >= 0;j += 2){
			cache[i] += cache[i - j] * 2;
		}
	}
	cout << cache[n];
    return 0;
}