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

const int MOD = 1000000007;

int N, start;

// 盤面に数が置いてあるかどうかをBitmaskで表す
// dp[i] := 盤面iのときに矛盾無く置かれている配置の総数
int dp[(1 << 25) + 1];

bool check() {

}

// f(i, j) := iの第jビットが0であり, 状態iから新たに数をjに置いても矛盾しない場合に1, 矛盾するなら0
// 要するに, 盤面iのときにjに置かれていなくて, かつ新しく置けるとき1
int f(int i, int j) {

}

// マスに数がすでに埋まっている→スキップ
// 小さい順に埋めていく
// 初期状態でその数を使っている→スキップ
void solve() {
  dp[0] = 1;
  FOR(i, 1, (1 << 25) + 1) {

    if ()
    REP(j, 25) {
      if ()
      // i - 1 << j := 盤面iからjマス目を引いたもの
      dp[i] += dp[i - (1 << j)] * f(i - (1 << j), j);
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  N = 0;
  start = 0;
  REP(i, 5) {
    REP(j, 5) {
      int x;
      cin >> x;
      if (x == 0) {
        N++;
      } else {
        start |= (1 << x);
      }
    }
  }

  solve();
  return 0;
}

