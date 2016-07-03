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

void solve() {
  ll pow10 = 10, ans = 0;
  REP(i, log10(N) + 1) {
    // 何周するか
    ans += (N / pow10) * (pow10 / 10);
    // あまりの部分
    ll n = N % pow10;
    // pow10/10以下なら0, 2*pow10/10以上ならpow10/10, 間なら間分足す
    if (pow10 / 10 <= n) {
      if (n < 2 * pow10 / 10) {
        ans += n % (pow10 / 10) + 1;
      } else {
        ans += pow10 / 10;
      }
    }
    pow10 *= 10;
  }
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  solve();
  return 0;
}
