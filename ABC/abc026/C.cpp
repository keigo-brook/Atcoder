/*
 * Created by KeigoOgawa on 4/18/16.
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

const int MAX_N = 20;

int N;
int b[MAX_N];
vector<vector<int> > boss;
int salary[MAX_N];

void solve() {
    RREP(i, N) {
        if (boss[i].size() == 0) {
            salary[i] = 1;
        } else {
            int maxs = 0, mins = INF;
            REP(j, boss[i].size()) {
                    maxs = max(maxs, salary[boss[i][j]]);
                    mins = min(mins, salary[boss[i][j]]);
            }
            salary[i] = 1 + maxs + mins;
        }
    }
    cout << salary[0] << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    boss.resize(N);
    FOR(i, 1, N) {
        cin >> b[i];
        boss[b[i] - 1].push_back(i);
    }

    solve();
    return 0;
}
