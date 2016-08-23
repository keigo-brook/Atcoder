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

const int MAX_N = 1e5;
int N, M, Q;
int g[10000][10000];


void solve(int x, int y, int z) {
  int m = -1;
  bool used[MAX_N];
  int minc[MAX_N];
  queue<int> q;
  z -= 2;
  while (z > 0) {
    REP(i, N) {
      if (g[x][i] > 0) {
        minc[i] = min(minc[i], g[x][i]);
      }
      if (g[y][i] > 0) {
        minc[i] = min(minc[i], g[y][i]);
        
      }

    }

  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = i;
    g[b][a] = i;
  }
  cin >> Q;
  REP(i, Q) {
    int x, y, z;
    cin >> x >> y >> z;
    solve(x, y, z);
  }
  return 0;
}
