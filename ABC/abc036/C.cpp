/*
 * Created by KeigoOgawa
 * 二分探索
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

const int MAX_N = 1e5;

int N;
vector<int> a(MAX_N);

// 7 8 1 1 3 3 6
// 1 3 6 7 8

// ソート→ユニーク→順位を二分探索
void solve() {
    vector<int> b = a;
    sort(all(b));
    auto last = unique(all(b));
    b.erase(last, b.end());
    REP(i, N) {
        auto lower = lower_bound(all(b), a[i]);
        if (a[i] == *lower) {
            cout << distance(b.begin(), lower) << endl;
        }
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    REP(i, N) {
        cin >> a[i];
    }
    
    solve();
    return 0;
}
