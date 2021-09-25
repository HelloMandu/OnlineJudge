#include<bits/stdc++.h>
using namespace std;

string str;
int idx;

string quadtree(){
    char cur = str[idx++];
    if(cur == 'b' || cur == 'w'){
        return string(1, cur);
    }
    
    string leftTop = quadtree();
    string rightTop = quadtree();
    string leftBottom = quadtree();
    string rightBottom = quadtree();
    return string(1, cur) + leftBottom + rightBottom + leftTop + rightTop;
}

int main(){
	// freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        idx = 0;
        cin >> str;
        cout << quadtree() << '\n';
    };
    return 0;
}