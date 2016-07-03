/*
 * Created by KeigoOgawa
 * treeDP
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

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

int N;
vector<int> G[MAX_N];

ll w[MAX_N], b[MAX_N];

void dfs(int n, int parent) {
    w[n] = 1, b[n] = 1;
    REP(i, G[n].size()) {
        if (parent != G[n][i]) {
            // 子を先に計算
            dfs(G[n][i], n);
            // 自分が白で子は両方
            (w[n] *= (w[G[n][i]] + b[G[n][i]])) %= MOD;
            // 自分が黒で子は白
            (b[n] *= w[G[n][i]]) %= MOD;
        }
    }
}

// 部分木について, 自分が黒で子が全部白 + 自分が白で子はどちらでも, としてTreeDP
void solve() {
    dfs(0, -1);
    cout << (w[0] + b[0]) % MOD << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N - 1) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    solve();
    return 0;
}
