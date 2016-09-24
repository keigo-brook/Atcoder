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

string s;
ll ans = 0;


// 残りの+を入れる数
bool dfs(int n, ll tmp, string ss) {
  if (n == 0) {
    ans += tmp + atoi(ss.c_str());
    return true;
  }
  if (ss.size() < 2 && n > 0) {
    return false;
  }
  REP(i, ss.size() - 1) {
    string tt = ss.substr(0, i + 1);
    dfs(n - 1, tmp + atoi(tt.c_str()), ss.substr(i + 1));
  }
  return true;
}

void solve() {
  REP(i, s.size() - 1) {
    dfs(i + 1, 0, s);
  }

  cout << ans + stol(s) << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;
  solve();
  return 0;
}
