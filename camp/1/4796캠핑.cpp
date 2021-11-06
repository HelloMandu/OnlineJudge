// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int l, p, v;
//     int cnt = 1;
//     while(true){
//         cin >> l >> p >> v;
//         if(!l && !p && !v){
//             break;
//         }
//         int result = 0;
//         while(v > 0){
//             v -= p;
//             if(v < 0){
//                 result += min(p + v, l);
//             } else{
//                 result += l;
//             }
//         }
//         cout << "Case " << cnt++ << ": " << result << '\n';
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

int calc(int i) {
	int sum = i;
	while (i) {
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int solution(int n) {
	for (int i = 1; i < 1000001; i++) {
		if (calc(i) == n) {
			return i;
		}
	}
    return 0;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}