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

const int MOD = 1e9+7;
int N;
string s;
ll ans = 0;

int edit_distance_dp(const string& str1, const string& str2) {
  int d[301][301];

  for (int i = 0; i < str1.size() + 1; i++) d[i][0] = i;
  for (int i = 0; i < str2.size() + 1; i++) d[0][i] = i;
  for (int i = 1; i < str1.size() + 1; i++)
    for (int j = 1; j < str2.size() + 1; j++)
      d[i][j] = min(min(d[i-1][j], d[i][j-1]) + 1, d[i-1][j-1] + (str1[i-1] == str2[j-1] ? 0 : 1));

  return d[str1.size()][str2.size()];
}

void dfs(int i, int n, string t) {

  if (i == 0) {
    t += "0";
  } else if (i == 1) {
    t += "1";
  } else if (t.size() > 0){
    t.erase(--t.end());
  }

  if (n == N) {
    if (s == t) {
      ans = (ans + 1) % MOD;
    }
    return;
  }

  debug(edit_distance_dp(t,s));
  if (edit_distance_dp(t, s) > N - n) return;

  REP(j, 3) {
    dfs(j, n + 1, t);
  }
}

void solve() {
  assert(N < 301);
  REP(i, 3) {
    dfs(i, 1, "");
  }
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  cin >> s;
  solve();
  return 0;
}
