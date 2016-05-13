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
#include <climits>

#define INF LLONG_MAX
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

ll N, H, A, B, C, D, E;

void solve() {
    // H + BX + DY - (N - X - Y)E > 0
    // を満たすX, Yを求める. Xを先に決めると,
    // Y > {(N - X)E - H - BX}/(D + E)
    // となり, Yが求まるので, X, Yの組み合わせが決まる.

    ll x = 0, ans = INF;
    while (x <= N) {
        ll y = ((N - x) * E - H - B * x);
        if (y > 0) {
            y = y / (D + E) + 1;
        } 
        y = max(0LL, y);

        if (0 <= y && y <= N) {
            ans = min(ans, A * x + C * y);
        }
        x++;
    }
    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> H;
    cin >> A >> B >> C >> D >> E;

    solve();
    return 0;
}
