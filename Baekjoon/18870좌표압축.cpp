#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> arr;
vector<int> input;
int result[1000001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
        input.push_back(num);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(int i = 0; i < n; i++){
        result[i] = lower_bound(arr.begin(), arr.end(), input[i]) - arr.begin();
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}