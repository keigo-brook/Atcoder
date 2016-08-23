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

const int MAX_M = 1e5;
int N, M;
bool used[MAX_M];
int c[MAX_M];

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  used[0]= true;
  REP(i, N) c[i] = 1;

  REP(i, M) {
    int x, y;

    cin >> x >> y;
    x--; y--;
    if (used[x]) {
      if (c[x] == 1) {
        used[x] = false;
      }
      used[y] = true;
    }
    c[x]--;
    c[y]++;
  }
  int ans = 0;
  REP(i, N) {
    if (used[i] && c[i] > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
