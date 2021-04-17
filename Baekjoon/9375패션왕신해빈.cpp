#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        string catag, name;
        map<string, int> m;
        cin >> n;
        while (n--) {
            cin >> name >> catag;
            if (m.find(catag) == m.end()) {
                m.insert(make_pair(catag, 1));
            }
            else{
                m[catag]++;
            }
        }
        int mul = 1;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
            mul *= (it->second + 1);
        }
        cout << mul - 1 << endl;
    }
    return 0;
}