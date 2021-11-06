#include<bits/stdc++.h>
using namespace std;

int alphabet[26];

int main() {
	int n, maxCnt = 0;
	char result;
    string str;
    cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z'){
			alphabet[str[i] - 'a']++;
        }
		else if ('A' <= str[i] && str[i] <= 'Z'){
			alphabet[str[i] - 'A']++;
        }
	}
    for(int i = 0; i < 26; i++){
        if(maxCnt <= alphabet[i]){
            result = maxCnt == alphabet[i] ? '?' : i + 'A';
            maxCnt = alphabet[i];
        }
    }
    cout << result;
	return 0;
}