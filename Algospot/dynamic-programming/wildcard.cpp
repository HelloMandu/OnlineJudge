#include<bits/stdc++.h>
using namespace std;

int cache[101][101];
string wildCard, word;

bool isWildCard(int _wildCardIndex = 0, int _wordIndex = 0){
    int wildCardIndex = _wildCardIndex;
    int wordIndex = _wordIndex;

    int& ret = cache[wildCardIndex][wordIndex];
    if(ret != -1){
        return ret;
    }

    while(
            wildCardIndex < wildCard.length() 
            && wordIndex < word.length() 
            && (wildCard[wildCardIndex] == '?' || wildCard[wildCardIndex] == word[wordIndex])){
        wildCardIndex++;
        wordIndex++;
    }

    if(wildCardIndex == wildCard.length()){
        return ret = (wordIndex == word.length());
    } else if(wildCard[wildCardIndex] != '*'){
        return ret = 0;
    }
    for(int i = wordIndex; i <= word.length(); i++){
        if(isWildCard(wildCardIndex + 1, i)){
            return ret = 1;
        }
    }
    return ret = 0;
}

int main(){
    // freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    vector<string> result;
    while(t--){
        result.clear();
        cin >> wildCard;
        int n;
        cin >> n;
        while(n--){
            cin >> word;
            memset(cache, -1, sizeof(cache));
            if(isWildCard(0, 0)){
                result.push_back(word);
            }
        }
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << '\n';
        }
    }
    return 0;
}