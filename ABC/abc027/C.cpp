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
typedef unsigned long long ull;
typedef pair<int, int> PII;

const ll MAX_N = 1e18;
ll N;

// 2x, 2x+１を辺とした木を作る.
// Nの深さの偶奇によって, AとBの最適な方向が変わる
// depthが偶数のとき, Aはなるべく右に, Bは左に行こうとする
void solve() {
    int depth = 0;
    for (ll n = N; n > 0; n /= 2) {
        depth++;
    }
    ll x = 1, i = 0;
    if (depth % 2 == 0) {
        while (x <= N) {
            if (i % 2 == 0) {
                x *= 2;
            } else {
                x = x * 2 + 1;
            }
            i++;
        }
    } else {
        while (x <= N) {
            if (i % 2 == 0) {
                x = x * 2 + 1;
            } else {
                x = x * 2;
            }
            i++;
        }
    }
    if (i % 2 != 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Takahashi" << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    solve();
    return 0;
}
