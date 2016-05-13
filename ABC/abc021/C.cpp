/*
 * Created by KeigoOgawa
 * 最短経路, トポロジカルソート, 数え上げDP
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

const int MAX_N = 100;
const int MOD = 1000000007;

struct edge {
    int to, cost;
    bool used;
};

int N, a, b, M;

// 頂点sからの最短距離
int d[MAX_N];
vector<edge> G[MAX_N];

void dijkstra1(int s) {
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<PII, vector<PII>, greater<PII> > que;
    fill(d, d + N, INF);
    d[s] = 0;
    que.push(PII(0, s));

    while (!que.empty()) {
        PII p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(PII(d[e.to], e.to));
            }
        }
    }
}

vector<edge> dag[MAX_N];
bool used[MAX_N];
int dp[MAX_N] = {0};
vector<int> l;
void visit(int n) {
    if (!used[n]) {
        used[n] = true;
        REP(i, dag[n].size()) {
            visit(dag[n][i].to);
        }
        l.push_back(n);
    }
}

// 頂点aからのすべての頂点への最短距離をd[1], d[2], ..., d[N]とする
// 道路が結んでいる辺を(i, j)とするとき, d[i] + (辺のコスト) = d[j] (その辺を通るのが最短路であるということ)
// が成り立つようなすべての辺でDAGを作れば, そのグラフをどのように辿っても絶対に最短路を達成可能
// このDAG上で, aからbにたどり着く経路の個数をDPで数える
// DAG上の経路は, トポロジカルソートを行って上からDPで数えていく
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> a >> b;
    a--; b--;
    cin >> M;

    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back((edge) {y, 1, false});
        G[y].push_back((edge) {x, 1, false});
    }

    // 頂点aからすべての頂点への最短経路dを求める
    dijkstra1(a);

    // d[i] + 1 = d[j]が成り立つようなすべての辺でDAGを作る
    REP(i, N) {
        REP(j, G[i].size()) {
            if (d[i] + 1 == d[G[i][j].to]) {
                dag[i].push_back((edge) {G[i][j].to, 1, false});
            }
        }
    }

    // DAGをトポロジカルソート
    REP(i, N) {
        visit(i);
    }

    // 数え上げDP
    dp[l[l.size() - 1]] = 1;
    RREP(i, l.size()) {
        REP(j, dag[l[i]].size()) {
            dp[dag[l[i]][j].to] += dp[l[i]] % MOD;
        }
    }

    cout << dp[b] << endl;

    return 0;
}