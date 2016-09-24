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

int N, x;
int a[2000];
int dp[2000][2];
int used[2000];
void solve() {
  ll ans = 0;
  cin >> N >> x;
  REP(i, N) {
    cin >> a[i];
    dp[i][0] = 0;
    dp[i][1] = a[i];
  }

  ll max_m = 0;
  REP(i, N) {
    int n = N;
    FOR(j, i + 1, i + N) {
      n--;
      int d = n * x;
      int b = a[j % N];
      if (dp[i][0] + dp[i][1] > d + b) {
        dp[i][0] = d;
        dp[i][1] = b;
        used[j % N] = MAX(used[j % N], n);
        max_m = MAX(dp[i][0], max_m);
      }
    }
  }
  REP(i, N) {
    ans += dp[i][1];
    if (used[i] > 0) {
      ans += (max_m / x - used[i]) * a[i];
    }
  }
  cout << ans + max_m << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
