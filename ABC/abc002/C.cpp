/*
 * Created by KeigoOgawa on 4/4/16.
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
#define FOR(i, a, b) for (int i=(a);i<(b);i++)
#define RFOR(i, a, b) for (int i=(b)-1;i>=(a);i--)
#define REP(i, n) for (int i=0;i<(n);i++)
#define RREP(i, n) for (int i=(n)-1;i>=0;i--)
#define MIN(a, b) (a>b?b:a)
#define MAX(a, b) (a>b?a:b)
#define debug(x) cout<<#x<<": "<<x<<endl
#define all(a) (a).begin(),(a).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

int xa, ya, xb, yb, xc, yc;

// (0, 0), (a, b), (c, d)の面積S = |ad - bc| / 2
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    x2 -= x1; x3 -= x1;
    y2 -= y1; y3 -= y1;
    return abs(x2 * y3 - y2 * x3) / 2.0;
}

void solve() {
    printf("%lf\n", triangle_area(xa, ya, xb, yb, xc, yc));
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    solve();
    return 0;
}
