//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//using namespace std;
////#pragma warning(disable:4996)
//
//int n, sum;
//int arr[5000005];
//map<int, int> Map;
//
//int main() {
//    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
//    //freopen("input.txt", "rt", stdin);
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> arr[i];
//    }
//    cin >> sum;
//    int result = 0;
//    for (int i = 0; i < n - 1; i++) {
//        if (Map.find(arr[i]) == Map.end()) {
//            bool flag = false;
//            for (int j = i + 1; j < n; j++) {
//                if (arr[i] + arr[j] == sum) {
//                    if (Map.find(arr[j]) == Map.end()) {
//                        Map[arr[i]] = arr[j];
//                        Map[arr[j]] = arr[i];
//                        flag = true;
//                        result++;
//                        break;
//                    }
//                }
//            }
//            if (!flag) {
//                Map[arr[i]] = -1;
//            }
//        }
//
//    }
//    cout << result;
//    return 0;
//}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//#pragma warning(disable:4996)

int n, sum;
int arr[5000005];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> sum;
    int start = 0, end = n - 1;
    int result = 0;
    map<int, int> Map;
    while (start < end) {
        if (arr[start] + arr[end] == sum) {
            if (Map.find(arr[start]) == Map.end()) {
                result++;
                Map[arr[start]] = arr[end];
                Map[arr[end]] = arr[start];
            }
            start++;
            end--;
        }
        else if (arr[start] + arr[end] < sum) {
            start++;
        }
        else {
            end--;
        }
    }
    cout << result;
    return 0;
}