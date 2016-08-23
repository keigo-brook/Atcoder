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
#define PI acos(-1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

double A, B, C;

double check(double t) {
  return A * t + B * sin(C * PI * t);
}

void solve() {
  double l = 0, h = 1000000, m;
  REP(i, 100) {
    m = (l + h) / 2.0;
    double f = check(m);
    if (f > 100) {
      h = m;
    } else if (f < 100){
      l = m;
    }
  }
  printf("%.11f\n", m);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>> A >> B >> C;
  solve();
  return 0;

}
