/*
 * Created by KeigoOgawa
 * 最短距離
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

const int MAX_N = 1000;
int ta[2], tb[2], T, V, n, xy[MAX_N][2]; 

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int maxd = T * V;

    REP(i, n) {
        double d1 = dist(ta[0], ta[1], xy[i][0], xy[i][1]) 
                 + dist(xy[i][0], xy[i][1], tb[0], tb[1]);
        if (d1 <= maxd) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> ta[0] >> ta[1] >> tb[0] >> tb[1] >> T >> V;
    cin >> n;
    REP(i, n) {
        cin >> xy[i][0] >> xy[i][1];
    } 

    solve();
    return 0;
}
