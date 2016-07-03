/*
 * Created by KeigoOgawa
 * 三分探索
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>

#define INF 1e18
#define EPS 1e-12
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

double P;

double f(double m) {
    double res = (m + P / pow(2, (m / 1.5)));
    return res;
}

double ternary_search(double h, double l) {
    REP(i, 1000) {
        if (f((h * 2 + l) / 3.0) < f((h + l * 2) / 3.0)) {
            l = (h + l * 2) / 3.0;
        } else {
            h = (h * 2 + l) / 3.0;
        }
    }
    return (h + l) / 2.0;
}

void solve() {
    double x = ternary_search(P, 0);
    printf("%.10lf\n", f(x));
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> P;
    
    solve();
    return 0;
}
