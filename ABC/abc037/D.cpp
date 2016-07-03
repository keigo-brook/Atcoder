/*
 * Created by KeigoOgawa
 * メモ化再帰
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>

#define INF (int)1e8
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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_HW = 1000;
const ll MOD = 1e9+7;

int H, W, a[MAX_HW][MAX_HW];
ll dp[MAX_HW][MAX_HW];

ll dfs(int x, int y) {
    if (dp[x][y] > 0) {
        return dp[x][y];
    }

    ll res = 1;
    REP(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < H && 0 <= ny && ny < W && a[nx][ny] > a[x][y]) {        
            res = (res + dfs(nx, ny)) % MOD;
        }
    }
    dp[x][y] = res;
    return res;
}

void solve() {
    ll ans = 0;
    REP(i, H) {
        REP(j, W) {
            ans = (ans + dfs(i, j)) % MOD;
        }
    }
    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> a[i][j];
        }
    }
    
    solve();
    return 0;
}
