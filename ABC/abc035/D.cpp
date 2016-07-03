/*
 * Created by KeigoOgawa
 * 最短距離
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
typedef pair<ll, ll> PII;

const int MAX_N = 1e5;
int N, M, T, a[MAX_N];

struct edge {
    ll to, cost;
    edge(ll to, ll cost) : to(to), cost(cost) {}
};
vector<vector<edge> > G(MAX_N), RG(MAX_N);

vector<ll> dijkstra1(int s, ll n, vector<vector<edge> > &Graph) {
    // pair<int, int>のfirstは最短距離,secondは頂点の番号
    // greater<P>を指定することでfirstが小さい順に取り出せるようにする
    priority_queue<PII, vector<PII>, greater<PII> > que;
    vector<ll> d(n, INF);
    d[s] = 0;
    que.push(PII(0, s));

    while (!que.empty()) {
        PII p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) {
            continue;
        }
        for (edge e : Graph[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(PII(d[e.to], e.to));
            }
        }
    }
    return d;
}


// 一番効率の良い街一つを訪問すれば良い
// 帰り道の最短 => すべての辺を逆にして最短路探索
void solve() {
    ll ans  = 0;
    vector<ll> d1  = dijkstra1(0, N, G);
    vector<ll> rd = dijkstra1(0, N, RG);

    REP(i, N) {
        if (d1[i] + rd[i] < T) {
            ans = MAX(ans, (T - d1[i] - rd[i]) * a[i]);
        }
    }
    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> T;
    REP(i, N) {
        cin >> a[i];
    }

    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(edge(b, c));
        RG[b].push_back(edge(a, c));
    }
    
    solve();
    return 0;
}
