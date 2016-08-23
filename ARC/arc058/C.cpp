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
  int ans1 = N, ans = N;
  while (1) {
    while (ans != 0) {
      if (ok[ans % 10]) break;
      ans /= 10;
    }
    if (ans == 0) {
      break;
    }
    ans = ans1 + 1;
    ans1++;
  }
  cout << ans1 << endl;
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
