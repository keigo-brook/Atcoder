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

const int MAX_N = (const int) 1e5;

int N, M, X, Y;
vector<int> a, b;

void solve() {
    int now = 0, time = 0, ans = 0;

    while (1) {
        if (now == 0) {
            auto next = lower_bound(all(a), time);
            if (next == a.end()) {
                break;
            }
            time = *next + X;
            now = 1;
        } else {
            auto next = lower_bound(all(b), time);
            if (next == b.end()) {
                break;
            }
            time = *next + Y;
            now = 0;
            ans++;
        }
    }
    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    cin >> X >> Y;

    a.resize(N);
    b.resize(M);

    REP(i, N) {
        cin >> a[i];
    }
    REP(i, M) {
        cin >> b[i];
    }

    solve();
    return 0;
}
