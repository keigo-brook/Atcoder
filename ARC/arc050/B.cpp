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
typedef pair<int, int> P;

ll R, B;
double x, y;

void solve() {
    ll a0 = MIN(R, B / y);
    ll b0 = MIN(B, R / x);
    ll ab = (B/y - R)/(1/y - x) + (((R/y) - (B*x/y)) / (1/y - x));
    ll t = max(a0, b0);
    cout << max(t, ab) << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> R >> B;
    cin >> x >> y;


    solve();
    return 0;
}
