/*
 * Created by KeigoOgawa
 * DP
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

int N;
int NG[3];
// can[i]: iに到達できる最小の回数
int can[301];

bool dfs() {
    int n = N, count = 1;
    fill(can, can + 301, INF);
    can[n] = 0;
    while (n > 0 && count < 100) {
        if (n == NG[0] || n == NG[1] || n == NG[2]) {
            n--;
            continue;
        }   
        count = can[n];

        FOR(i, 1, 4) {
            if (n - i < 0) {
                break;
            }
            if (n - i == NG[0] || n - i == NG[1] || n - i == NG[2]) {
                continue;
            }
            can[n - i] = min(can[n - i], count + 1);
        }
        n--;
    }
    if (can[0] != INF && can[0] <= 100) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    if (dfs()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> NG[0] >> NG[1] >> NG[2];
    
    solve();
    return 0;
}
