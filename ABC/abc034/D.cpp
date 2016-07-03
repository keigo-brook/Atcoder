/*
 * Created by KeigoOgawa
 * 二分探索
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>
#include <array>

#define INF 1e8
#define EPS 1e-10
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
#define debug(x) cout << #x << ": " << x << endl
#define all(a) (a).begin(), (a).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int MAX_N = 1000;
int K, N, w[MAX_N], p[MAX_N];

// c%以上の食塩水を作れるかどうか
bool check(double c) {
    // c%の食塩水を作るとき, 何グラムの食塩が余るかを計算
    vector<double> solt(N);
    REP(i, N) {
        solt[i] = w[i] * (p[i] - c) / 100.0;
    }

    // 余る食塩が多い順にK個入れる
    sort(all(solt), greater<double>());
    double sum = 0;
    REP(i, K) {
        sum += solt[i];
    }
    // もし合計が0以上であればc%以上の食塩水を作れる
    return sum >= 0;
}


void solve() {
    double h = 100, l = 0;
    double m = (h + l) / 2;
    REP(i, 100) {
        if (check(m)) {
            l = m;
        } else {
            h = m;
        }
        m = (h + l) / 2.0;
    }
    printf("%lf\n", m);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    REP(i, N) {
        cin >> w[i] >> p[i];
    }
    
    solve();
    return 0;
}
