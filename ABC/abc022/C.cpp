/*
 * Created by KeigoOgawa
 * 最短閉路, ワーシャルフロイド
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

const int MAX_N = 300;
const int MAX_M = MAX_N*(MAX_N - 1) / 2;

int N, M;
int cost[MAX_N][MAX_N];
int d[MAX_N][MAX_N];

void warshall_floyd() {
    REP(k, N) {
        REP(i, N) {
            REP(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// 最短閉路 -> 頂点に隣接する辺を除いて, 点対の最短経路を求める ->
// 最短経路と頂点に隣接する辺の長さを足す
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int adj1c = 0, adj1[MAX_N][MAX_N];

    cin >> N >> M;

    // init d
    fill(d[0], d[N], INF);
    REP(i, N) {
        d[i][i] = 0;
    }

    REP(i, M) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;

        // 頂点1に隣接する辺を除いたグラフと, 頂点1に隣接する辺で分ける
        if (u != 0 && v != 0) {
            d[u][v] = d[v][u] = l;
        } else {
            adj1[adj1c][0] = max(u, v);
            adj1[adj1c][1] = l;
            adj1c++;
        }
    }

    // 頂点1に隣接する辺を除いたグラフの全点対の最短経路を計算する 
    warshall_floyd();

    int ans = INF;
    // 頂点1に隣接する頂点のうち, どの二つを閉路に含めるか全通り試す
    REP(i, adj1c) {
        FOR(j, i + 1, adj1c) {
            // 前計算した最短経路の結果と合わせて最短経路の長さを求める
            ans = min(ans, d[adj1[i][0]][adj1[j][0]] + adj1[i][1] + adj1[j][1]);
        }
    }
    
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
