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
bool used[28];
void solve() {
  REP(i, s.size()) {
    char c = s[i];
    if (used[28 - (c - 'a')]) continue;
    used[28 - (c - 'a')] = true;
    int t = i;
    FOR(j, i + 1, s.size()) {
      if (s[j] == c) {
        if ((j - t - 1) < 2) {
          cout << t+1 << " " << j+1 << endl;
          return;
        }
        t = j;
      }
    }
  }
  cout << "-1 -1" << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> s;
  solve();
  return 0;
}
