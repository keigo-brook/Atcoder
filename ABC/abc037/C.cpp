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

const ll MAX_N = 1e5;
ll N, K, a[MAX_N], imos[MAX_N + 1];

void solve() {
    ll ans = 0;
    REP(i, N - K + 1) {
        imos[i]++;
        imos[i + K]--;
    } 
    REP(i, N + 1) {
        imos[i + 1] += imos[i];
    }
    REP(i, N) {
        ans += a[i] * imos[i];
    }

    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K;
    REP(i, N) {
        cin >> a[i];
    }

    solve();
    return 0;
}
