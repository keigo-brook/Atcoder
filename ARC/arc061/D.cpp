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

vector<int> p[(int)1e9];
int H, W, N;
ll ans[10];

int dx[9] = {0, 0, 0, -1, -2, -2, -2, -1, -1};
int dy[9] = {2, 1, 0, 0, 0, 1, 2, 2, 1};

void solve() {
  REP(i, 1e9) {
    if (p[i].size() == 0) continue;
    REP(j, p[i].size()) {
      int x = i, y = p[i][j];
      REP(k, 9) {
        int xx = x - dx[k], yy = y - dy[k];
        if (xx < 0 || W < x || yy < 0 || H < yy || xx + 2 > W || yy - 2 > H) {
          break;
        }
      }

    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W >> N;
  ans[0] = (H - 2) * (W - 2);
  REP(i, N) {
    int a, b;
    cin >> a >> b;
    p[a-1].push_back(b-1);
  }
  solve();
  return 0;
}
