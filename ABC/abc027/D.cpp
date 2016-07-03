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

const int MAX_S = 1e5;
string s;

/*
  右を>, 左を<とする
  +という記号のときの変化量は, (その記号より左の>) - (その記号より左の<)
  視点を変えると,
  < のときの変化量は, (右の+) - (右の-)
  Mのときに, 上記を数えて, ソートしてから半々に分ける
  はじめに合計を数えておく
 */
void solve() {
  vector<int> c;
  int h = 0;
  // 合計の+-を計算
  REP(i, s.size()) {
    if (s[i] == '+') {
      h++;
    } else if (s[i] == '-') {
      h--;
    }
  }
  REP(i, s.size()) {
    // Mであったらそのときの変化量を保存
    if (s[i] == '+') {
      h++;
    } else if (s[i] == '-') {
      h--;
    } else if (s[i] == 'M') {
      c.push_back(h);
    }
  }

  // ソートして半々で足し引く
  int ans = 0;
  sort(all(c));
  REP(i, c.size() / 2) {
    ans += c[c.size() - 1 - i] - c[i];
  }
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> s;
  solve();

  return 0;
}
