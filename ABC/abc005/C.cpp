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
const int MAX_M = 100;

int T, N, A[MAX_N], M, B[MAX_M];

bool used[MAX_N];

bool check(int i) {
    REP(j, N) {
        if (B[i] >= A[j] && A[j] >= B[i] - T && !used[j]) {
            used[j] = true;
            return true;
        }
    }
    return false;
}

// 範囲内にあるたこ焼きを貪欲に売っていけるかどうか判定
void solve() {
    REP(i, M) {
        if (!check(i)) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    cin >> M;
    REP(i, M) {
        cin >> B[i];
    }
    
    solve();
    return 0;
}
