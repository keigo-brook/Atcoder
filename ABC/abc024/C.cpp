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

const int MAX_N = 1e9;
const int MAX_D = 1e4;
const int MAX_K = 100;

int N, D, K;
int ans[MAX_K];
int now[MAX_K];

int LR[2][MAX_D];
int ST[2][MAX_K];

// 貪欲にその日にいけるところまで行く
void solve() {
    REP(i, D) {
        REP(j, K) {
            if (now[j] != ST[1][j] && LR[0][i] <= now[j] && now[j] <= LR[1][i]) {
                if (LR[0][i] <= ST[1][j] && ST[1][j] <= LR[1][i]) {
                    now[j] = ST[1][j];
                    ans[j] = i;
                } else {
                    if (ST[1][j] < LR[0][i]) {
                        now[j] = LR[0][i];
                    } else {
                        now[j] = LR[1][i];
                    }
                }
            }
        }
    } 

    REP(i, K) {
        cout << ans[i] + 1 << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> D >> K;
    REP(i, D) {
        cin >> LR[0][i] >> LR[1][i];
        LR[0][i]--;
        LR[1][i]--;
    }

    REP(i, K) {
        cin >> ST[0][i] >> ST[1][i];
        ST[0][i]--;
        ST[1][i]--;
        now[i] = ST[0][i];
    }

    solve();
    return 0;
}
