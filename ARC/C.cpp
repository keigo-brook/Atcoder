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

int N, K;
bool ok[10];

void solve() {
  int mi;
  REP(i, 10) {
    if (!ok[i]) {
      mi = i;
      break;
    }
  }
  debug(N);
  int ans = 1;
  while (N != 0) {
    debug(N);
    int mo = N % 10;
    if (ok[9] && mo == 9) {
      N -= (N % 100);
      N += mi * 10 + mi;
    } else if (ok[mo]) {
      FOR(i, mo + 1, 10) {
        if (!ok[i]) {
          N = N - (N % 10) + i;
          break;
        }
      }
    } else if (!ok[mo]) {
      ans = ans * 10 + mo;
      N /= 10;
    }
  }
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  REP(i, K) {
    int a;
    cin >> a;
    ok[a] = true;
  }
  solve();
  return 0;
}
