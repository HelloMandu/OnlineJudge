#include<bits/stdc++.h>
using namespace std;

const int INFINITE = 987654321;
int n;
int fences[200001];

int getMaxRectangle(int start, int end){
    if(start == end){
        return fences[start];
    }
    int mid = (start + end) / 2;
    int sideRectangle = max(getMaxRectangle(start, mid), getMaxRectangle(mid + 1, end));

    int minHeight = min(fences[mid], fences[mid + 1]);
    int crossRectangle = minHeight * 2;
    int left = mid - 1, right = mid + 2;
    while(left >= start && right <= end){
        if(fences[left] < fences[right]){
            minHeight = min(minHeight, fences[right]);
            right++;
        } else{
            minHeight = min(minHeight, fences[left]);
            left--;
        }
        crossRectangle = max(crossRectangle, minHeight * (right - left - 1));
    }
    while(right <= end){
        minHeight = min(minHeight, fences[right]);
        crossRectangle = max(crossRectangle, minHeight * (right - start + 1));
        right++;
    }
    while(left >= start){
        minHeight = min(minHeight, fences[left]);
        crossRectangle = max(crossRectangle, minHeight * (end - left + 1));
        left--;
    }

    return max(sideRectangle, crossRectangle);
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> fences[i];
        }
        cout << getMaxRectangle(0, n - 1) << '\n';
    }
    return 0;
}