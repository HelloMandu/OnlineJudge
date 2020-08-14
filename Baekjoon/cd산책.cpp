#include <iostream>
using namespace std;

int map[1001][1001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        int h, w, n;
        cin >> h >> w >> n;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> map[i][j];
            }
        }
        int days = 0;
        int row, col;
        while (days < n) {
            row = 1, col = 1;
            while (row <= h && col <= w) {
                if (map[row][col]) {
                    map[row][col++] = 0;
                }
                else {
                    map[row++][col] = 1;
                }
            }
            days++;
        }
        cout << "Case #" << t << '\n' << row << ' ' << col << '\n';
    }
    return 0;
}