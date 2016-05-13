/*
 * Created by KeigoOgawa
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>

#define INF (int)1e8
#define EPS 1e-10
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
#define debug(x) cout << #x << ": " << x << endl
#define all(a) (a).begin(), (a).end()

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 50;

int N;
int a[MAX_N];

void solve() {
    int maxa = -INF;
    REP(i, N) {
        int suma = 0, maxb = -INF, maxbi = -1;
        for (int j = 0; j < N; j++) {
            int sumb = 0;
            if (j == i) {
                continue;
            }
            for (int k = min(i, j) + 1; k <= max(i, j); k += 2) {
                sumb += a[k];
            }
            if (sumb > maxb) {
                maxbi = j;
                maxb = sumb;
            }
        }

        if (maxbi != -1) {
            for (int j = min(i, maxbi); j <= max(i, maxbi); j += 2) {
                suma += a[j];
            }

            if (suma > maxa) {
                maxa = suma;
            }
        }
    }

    cout << maxa << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) { cin >> a[i]; }

    solve();
    return 0;
}
