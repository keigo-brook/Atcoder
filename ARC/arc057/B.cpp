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

int N;
ll K;
ll a[2000];
// dp[i][j] = i日目までにj回勝率が上昇した場合の勝利数の最小値
ll dp[2000][2000];
ll suma = 0;
void solve() {
  fill(dp[0], dp[0] + N, INF);
  dp[0][0] = 0;
  REP(i, N) {
    REP(j, N) {
      
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  REP(i, N) {
    cin >> a[i];
    suma += a[i];
  }
  solve();
  return 0;
}
