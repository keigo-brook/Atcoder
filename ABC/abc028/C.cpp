/*
 * Created by KeigoOgawa on 4/16/16.
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

int n[5];

void solve() {
    int max1 = 0, max2 = 0, max3 = 0;
    REP(i, 5) {
        FOR(j, i + 1, 5) {
            int now = 0;
            REP(k, 5) {
                if (k != i && k != j) {
                    now += n[k];
                }
            }

            if (now > max1) {
                swap(now, max1);
            }
            if (now > max2) {
                swap(now, max2);
            }
            if (now > max3) {
                swap(now, max3);
            }
        }
    }
    cout << max3 << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];

    solve();
    return 0;
}
