/*
 * Created by KeigoOgawa
 * DFS, XOR
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

const int MAX_N = 5;
int N, K;
int T[MAX_N][MAX_N];

bool dfs(int i, int now) {
    if (i == N) {
        return now == 0;
    }

    REP(k, K) {
        if (dfs(i + 1, now ^ T[i][k])) {
            return true;
        }
    }

    return false;
}

void solve() {
    if (dfs(0, 0)) {
        cout << "Found";
    } else {
        cout << "Nothing";
    }
    cout << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i, N) {
        REP(j, K) {
            cin >> T[i][j]; 
        }
    }

    solve();
    return 0;
}
