#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        list<char> List;
        string str;
        list<char>::iterator it = List.begin();
        cin >> str;
        for(int i = 0; i < str.length(); i++){
            char cur = str[i];
            if(cur == '<'){
                if(it != List.begin()){
                    it--;
                }
            } else if(cur == '>'){
                if(it != List.end()) {
				    it++;
			    }
            } else if(cur == '-'){
                if(it != List.begin()){
                    it = List.erase(--it);
                }
            } else{
                List.insert(it, cur);
            }
        }
        for(list<char>::iterator it = List.begin(); it != List.end(); it++){
            cout << *it;
        }
        cout << '\n';
    }
    return 0;
}