/*
 * Created by KeigoOgawa
 * 二分探索, 最短経路, ダイクストラ
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>
#include <string>

#define INF (ll)1e15
#define EPS 1e-10
#define FOR(i, a, b) for (int i=(a);i<(b);i++)
#define RFOR(i, a, b) for (int i=(b)-1;i>=(a);i--)
#define REP(i, n) for (int i=0;i<(n);i++)
#define RREP(i, n) for (int i=(n)-1;i>=0;i--)
#define MIN(a, b) (a>b?b:a)
#define MAX(a, b) (a>b?a:b)
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(a) (a).begin(),(a).end()


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int MAX_HW = 10;

int H, W, T, S, G;
vector<string> hw(MAX_HW);

ll d[100];
bool used[100];

void dijkstra(int s, ll x) {
    int V = H*W;
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while (true) {
        int v = -1;

        // まだ使われていない頂点のうち距離が最小のものを探す
        for (int u = 0; u < V; ++u) {
            if (!used[u] && (v == -1 || d[u] < d[v])) {
                v = u;
            }
        }

        if (v == -1) {
            break;
        }
        used[v] = true;

        for (int u = 0; u < V; ++u) {
            ll vi = v / W, vj = v % W, ui = u / W, uj = u % W;
            // 上下左右
            if ((vi == ui && (vj == uj + 1 || vj == uj - 1)) ||
             (vj == uj && (vi == ui + 1 || vi == ui - 1))) {
                ll cost;
                if (hw[ui][uj] == '.' || hw[ui][uj] == 'S' || hw[ui][uj] == 'G') {
                    cost = 1;
                } else {
                    cost = x;
                }
                d[u] = min(d[u], d[v] + cost);
            }
        }
    }
}

// xを変化させて最短路探索, xは二分探索で
void solve() {
    // 二分探索
    ll lo = 1, hi = T;
    while (hi - lo > 1) {
        ll x = (lo + hi) / 2;
        dijkstra(S, x);
        if (d[G] <= T) {
            lo = x;
        } else {
            hi = x;
        }
    }
    cout << lo << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> T;
    REP(i, H) {
        cin >> hw[i];
        REP(j, hw[i].size()) {
            if (hw[i][j] == 'S') {
                S = i * W + j;
            } else if (hw[i][j] == 'G') {
                G = i * W + j;
            }
        }
    }
    solve();
    return 0;
}
