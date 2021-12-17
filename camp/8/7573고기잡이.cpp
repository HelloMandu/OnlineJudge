#include<bits/stdc++.h>
using namespace std;

int n, i, m;
vector<pair<int, int> > fishes;
vector<pair<int, int> > blocks;

void initBlocks(){
    int region = i / 2;
    for(int i = 1; i < region; i++){
        blocks.push_back(make_pair(i, region - i));
    }
}

int isRange(int y, int x){
    return y <= n && x <= n;
}

bool canGrab(pair<int, int> start, pair<int, int> end, pair<int, int> fish){
    int y = start.first, x = start.second;
    int ny = end.first, nx = end.second;
    int fy = fish.first, fx = fish.second;
    return y <= fy && ny >= fy && x <= fx && nx >= fx;
}

int getFishes(pair<int, int> l, pair<int, int> r){
    int cnt = 0; 
    for(int i = 0; i < fishes.size(); i++){
        cnt += canGrab(l, r, fishes[i]);
    }
    return cnt;
}

int getFishes(int y, int x){
    int result = 0;
    for(int l = 0; l < blocks.size(); l++){
        int r = blocks[l].first, c = blocks[l].second;
        for(int i = y - r; i < y; i++){
            for(int j = x - c; j < x; j++){
                result = max(result, getFishes(make_pair(i, j), make_pair(i + r, j + c)));
            }
        }
    }
    return result;
}

int solution(){
    int result = 0;
    for(int i = 0; i < fishes.size(); i++){
        result = max(result, getFishes(fishes[i].first, fishes[i].second));
    }
    return result;
}

int main(){
    cin >> n >> i >> m;
    for(int i = 0; i < m; i++){
        int y, x;
        cin >> y >> x;
        fishes.push_back(make_pair(y, x));
    }
    initBlocks();
    cout << solution();
    return 0;
}