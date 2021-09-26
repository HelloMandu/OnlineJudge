/**
 * TODO: resolve
*/
#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long arrN[101], arrM[101];
long long jLis[101][101];
const long long MINIMUM = numeric_limits<long long>::min();

long long getJLis(int indexN, int indexM){
    long long& ret = jLis[indexN + 1][indexM + 1];
    if(ret != -1){
        return ret;
    }

    long long limitN = indexN == -1 ? MINIMUM : arrN[indexN];
    long long limitM = indexM == -1 ? MINIMUM : arrM[indexM];
    long long limit = max(limitN, limitM);
    ret = 2;
    for(int i = indexN + 1; i < n; i++){
        if(limit < arrN[i]){
            ret = max(getJLis(i, indexM) + 1, ret);
        }
    }
    for(int i = indexM + 1; i < m; i++){
        if(limit < arrM[i]){
            ret = max(getJLis(indexN, i) + 1, ret);
        }
    }
    return ret;
}

int main() {
	freopen("../input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
        cin >> n >> m;
        memset(jLis, -1, sizeof(jLis));
        for(int i = 0; i < n; i++){
            cin >> arrN[i];
        }
        for(int i = 0; i < m; i++){
            cin >> arrM[i];
        }
        cout << getJLis(-1, -1) - 2 << '\n';
	}
	return 0;
}