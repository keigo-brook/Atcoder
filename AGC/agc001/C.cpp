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

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};
typedef vector<vector<edge> > Graph;
Graph G(2001);

void add_edge(int from, int to, int cost) {
  G[from].push_back(edge(to, cost));
}

int N, K;

// depthが正の間頂点を数える
int countV(int p, int v, int depth) {
  int c = 1;
  if (depth) {
    for (edge e : G[v]) {
      if (e.to != p) {
        c += countV(v, e.to, depth - 1);
      }
    }
  }
  return c;
}

void solve() {
  int ans = 0;
  if (K % 2 == 0) {
    // 直径が偶数→すべての頂点に関して, 距離K/2以上の頂点を数え,それの最小値が答え
    REP(i, N) {
      ans = max(ans, countV(-1, i, K/2));
    }
  } else {
    // 直径が奇数→すべての辺に関して, 距離(K - 1)/2 以上となる頂点を数え, それの最小値が答え
    REP(i, N) {
      for (edge e : G[i]) {
        int l = countV(e.to, i, K/2);
        int r = countV(i, e.to, K/2);
        ans = max(ans, l + r);
      }
    }
  }
  cout << N - ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    add_edge(a - 1, b - 1, 1);
    add_edge(b - 1, a - 1, 1);
  }
  solve();
  return 0;
}
