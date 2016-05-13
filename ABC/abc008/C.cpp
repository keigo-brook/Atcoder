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

const int MAX_N = 100;

int N, C[MAX_N];

// あるコインが表を向いている組み合わせをN!で割った値=そのコインが表を向いて終了する確率
// 各コインが, 表を向いた状態で終了する確率の足し合わせを求める
// あるコインCの約数はS個ある. 表裏に関係あるのは約数だけであるので, 
// このS個の並べ方であるS!通りについて考える.
// S!通りのうち, Cが何番目にあるかどうかは等確率である.
// また, 約数の並べ方のうち, 表になるのはCの左側に偶数枚の約数があるとき, 
// つまりCが左から奇数番目にあるとき.
// このような並べ方の確率は, Sが奇数個のとき確率1/2で, 
// Sが偶数個のとき確率(S + 2)/(2S + 2)である
// それぞれのコイン毎にこれを求め, 足し合わせると解となる

void solve() {
    double ans = 0;
    sort(C, C + N);
    REP(i, N) {
        // 約数を数える
        int sc = 0;
        REP(j, N) {
            if (C[i] % C[j] == 0) {
                sc++;
            }
        }
        // 自分を除く
        sc--;

        // 個数に応じて確率を答えに足す
        if (sc % 2 == 0) {
            ans += (sc + 2) / (2.0 * sc + 2.0);
        } else {
            ans += 0.5;
        }
    }
    printf("%lf\n", ans);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> C[i];
    }
    
    solve();
    return 0;
}
