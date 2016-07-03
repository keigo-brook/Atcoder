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

const int MAX_N = 16;

int M, N, mat[MAX_N];
ll dp[1 << MAX_N];


/*
  大小関係→有向辺と考え, トポロジカルソートの総数を数え上げる問題に帰着
  頂点の集合をSとし,
  f(s) := (Sをトポロジカルソートする方法の通り数)
  と定義する.
  f(φ) = 1, f(全頂点集合)が求めたい答え.
  Sに, ある頂点vを追加することを考える.
  vを入れてトポロジカルソートしたときに, vを一番右におくことができれば, f(S) += f(S-{v}) とできる.
  vを一番右に置くことができるのは, vからS-{v}へ向かう辺が無いとき.
  これをすべての頂点集合に対して, bitDPで求める.
 */
void solve() {
  dp[0] = 1;
  // 頂点集合s
  REP(s, 1 << N) {
    REP(v, N) {
      // 頂点vがsに含まれる
      if (s & (1 << v)) {
        // vからs-vへの有向辺がない
        if ((mat[v] & s) == 0) {
          // vをsの一番右に追加できる
          // s ^ (1 << v) ：sからvを除いた集合
          dp[s] += dp[s ^ (1 << v)];
        }
      }
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    // bit隣接行列を作成
    mat[a - 1] |= (1 << (b - 1));
  }
  solve();
  return 0;
}
