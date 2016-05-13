/*
 * Created by KeigoOgawa
 * Greedy
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

const int MAX_N = 100;

int N, K, R[MAX_N];

// ソートして貪欲
void solve() {
    sort(R, R + N);
    double rate = 0;
    FOR(i, N - K, N) {
        rate = (rate + R[i])/ 2;
    }
    printf("%lf\n", rate);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    REP(i, N) {
        cin >> R[i];
    }
    
    solve();
    return 0;
}
