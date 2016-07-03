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

const int MAX_N = 2000;
ll N, x[MAX_N], y[MAX_N];

// 点を一つ固定し, 他の点についてその点との角度を求める. 角度はatan2で求められる.
// 2点について, 角度の差から鈍角と直角を見つける
// すべての点について行い, 最終的に鋭角の数は全体から鈍角と直角を引いたものとなる
void solve() {
    ll don = 0, tyoku = 0, ei = 0;
    REP(i, N) {
        vector<long double> deg;
        // 点(x[i], y[i])から他のすべての点へのベクトルの角度をもとめ, ソートする
        REP(j, N) {
            if (i != j) {
                deg.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            }
        }
        sort(all(deg));

        // 2週目を追加
        REP(i, 2*(N - 1)) {   
            deg.push_back(deg[i] + 2 * M_PI);
        }

        // しゃくとり法で鈍角, 直角の個数を数える
        int s = 0, t = 0;
        REP(i, N - 1) {
            // s: 90度以上となる最初の点
            while (deg[s] - deg[i] < M_PI / 2 - EPS) {
                s++;
            }
            // t: 180度以上となる最初の点
            while (deg[t] - deg[i] < M_PI + EPS) {
                t++;
            }
            // deg[s] = deg[i] + pi/2 のとき, 直角
            if (fabs(deg[i] + M_PI / 2 - deg[s]) < 2 * EPS) {
                tyoku++;
                s++;
            }
            don += t - s;
        }
    }

    // 全体から鈍角, 直角の個数を引き鋭角の個数を計算
    ei = (N * (N - 1) * (N - 2) / 6) - don - tyoku;

    cout << ei << " " << tyoku << " " << don << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    REP(i, N) {
        cin >> x[i] >> y[i];
    }

    solve();
    return 0;
}
