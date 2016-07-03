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
int N, a, b[MAX_N];
string k;

void solve() {
  int used[MAX_N];
  fill(used, used + MAX_N, -1);
  int i = 0, c = 0, t = 0, aa = a;
  while (true) {
    int now = aa;

    // 閉路が検出されたとき
    if (used[now] != -1) {
      c = i - used[now] + 1;
      t = used[now];
      // 一桁づつModを取る
      int k_mod_c = 0;
      REP(j, k.size()) {
        k_mod_c = (k_mod_c * 10 + k[j] - '0') % c;
      }
      // 閉路に突入するようにk_mod_cを調整
      while (k_mod_c < t) {
        k_mod_c += c;
      }
      // 初めからシミュレート
      aa = a;
      REP(j, k_mod_c) {
        now = aa;
        aa = b[now];
      }
      cout << aa + 1 << endl;
      return;
    }

    aa = b[now];
    used[now] = ++i;

    // k <= nのとき, シミュレート結果をそのまま表示
    if (k.size() < 6 && stoi(k) == i) {
      cout << aa + 1 << endl;
      return;
    }

  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> a;
  cin >> k;
  a--;
  REP(i, N) {
    cin >> b[i];
    b[i]--;
  }
  solve();
  return 0;
}
