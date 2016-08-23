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
int N, L;
int a[MAX_N];

void solve() {
  int s = -1;
  REP(i, N - 1) {
    if (a[i] + a[i + 1] >= L) {
      s = i + 1;
      break;
    }
  }
  if (s == -1 ) {
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
    RFOR(i, s, N - 1) {
      cout << i+1 << endl;
    }
    FOR(i, 0, s) {
      cout << i+1 << endl;
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> L;
  REP(i, N) {
    cin >> a[i];
  }
  solve();
  return 0;
}
