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

const int MAX_N = 100000;

int R, C, K, N;
int r[MAX_N], c[MAX_N];

void solve() {
    // 各行, 各列について飴が何個あるのか計算
    vector<int> drop_row(R, 0);
    vector<int> drop_col(C, 0);
    REP(i, N) {
        drop_row[r[i]]++;
        drop_col[c[i]]++;
    }

    // 飴がX個ある行（列）がY個あるという情報を行, 列ごとにまとめる
    vector<int> drop_num_row(N + 1, 0);
    vector<int> drop_num_col(N + 1, 0);
    REP(i, R) {
        drop_num_row[drop_row[i]]++;
    }

    REP(i, C) {
        drop_num_col[drop_col[i]]++;
    }

    // (行からi個の飴)*(列からK-i個の飴)を計算
    ll ans = 0;
    REP(i, K + 1) {
        ans += drop_num_row[i] * drop_num_col[K - i];            
    }

    REP(i, N) {
        // マスに飴があり, 和がK個となるマス数を引く
        if (drop_row[r[i]] + drop_col[c[i]] == K) {
            ans--;
        }
        // 起点に飴があり, 和がK+1個となるマス数を足す
        if (drop_row[r[i]] + drop_col[c[i]] == K + 1) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    cin >> R >> C >> K;
    cin >> N;

    REP(i, N) {
        int rt, ct;
        cin >> rt >> ct;
        r[i] = rt - 1;
        c[i] = ct - 1;
    }
    solve();
    return 0;
}
