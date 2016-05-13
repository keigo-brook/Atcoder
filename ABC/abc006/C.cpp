/*
 * Created by KeigoOgawa
 * 鶴亀算
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

int N, M;

// はじめに全部子供と仮定して, 差分を老人, 大人で合わせる
void solve() {
    int child = N, old = 0, adult = 0;
    int maxm = 4 * child;
    int diff = maxm - M;

    if (diff < 0) {
        cout << "-1 -1 -1" << endl;
        return;
    }

    if (diff % 2 == 1) {
        old = 1;
        diff--;
        child--;
    }

    adult = diff / 2;
    child  -= adult;

    if (child >= 0 && adult >= 0 && old >= 0) {
        cout << adult << ' ' << old << ' ' << child << endl;
    } else {
        cout << "-1 -1 -1" << endl;        
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> M;

    solve();
    return 0;
}
