/*
 * Created by KeigoOgawa
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>

#define INF 1e15
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

const int MAX_N = 200;
const int MAX_W = 1000;
const int MAX_V = 1000;

int N, W, v[MAX_N], w[MAX_N], dataset;


// N ≤ 30
// 半分全列挙
void dataset1() {
    //　(重さ, 価値)のペア
    pair<ll, ll> ps[1 << (30 / 2)];
    // 前半分を全列挙
    int n2 = N / 2;
    REP(i, 1 << n2) {
        ll sw = 0, sv = 0;
        REP(j, n2) {
            if (i >> j & 1) {
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }

    // 重くて価値の低い無駄な要素を取り除く
    sort(ps, ps + (1 << n2));
    int m = 1;
    for (int i = 1; i < 1 << n2; i++) {
        if (ps[m - 1].second < ps[i].second) {
            ps[m++] = ps[i];
        }
    }

    // 後ろ半分を全列挙し解を求める
    ll res = 0;
    REP(i, 1 << (N - n2)) {
        ll sw = 0, sv = 0;
        REP(j, N - n2) {
            if (i >> j & 1) {
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }
        if (sw <= W) {
            ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, (ll)INF)) - 1)->second;
            res = max(res, sv + tv);
        }
    }
    cout << res << endl;
}

// N ≤ 200, w[i] ≤ 1000
// 重さに対する最大の価値でDP
void dataset2() {
    ll dp[MAX_N + 1][MAX_N * MAX_W + 1];
    RREP(i, N) {
        REP(j, W + 1) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[0][W] << endl;
}


// N ≤ 200, v[i] ≤ 1000
// 価値に対する最小の重さでDP
void dataset3() {
    ll dp[MAX_N + 1][MAX_N * MAX_V + 1];
    fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
    dp[0][0] = 0;
    REP(i, N) {
        REP(j, MAX_N * MAX_V + 1) {
            if (j < v[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }
    // 重さがW以下で最大の価値iが解
    ll res = 0;
    REP(i, MAX_N * MAX_V + 1) {
        if (dp[N][i] <= W) {
            res = i;
        }
    }
    cout << res << endl;
}

void solve() {
    switch (dataset) {
    case 1:
        dataset1();
        break;
    case 2:
        dataset2();
        break;
    case 3:
        dataset3();
        break;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    dataset = 0;
    cin >> N >> W;
    if (N <= 30) {
        dataset = 1;
    }
    REP(i, N) {
        cin >> v[i] >> w[i];
        if (dataset != 1 && v[i] > 1000) {
            dataset = 2;
        } else if (dataset != 1 && w[i] > 1000) {
            dataset = 3;
        }
    }
    
    solve();
    return 0;
}
