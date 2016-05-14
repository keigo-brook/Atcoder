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

string S;

// 奇数回現れる文字がk種類あるとする
// 少なくともk個の回文にしなくてはならない
// N-k個については, (N-K)/2組のペアを作ることができて, これをk個の回文に割り振る
// よって, (N - K)/ 2K 組のペアを割り振る
// K = 0のとき, X = N,
// K > 1のとき, X = 2 ((N - K) / 2K)) + 1 (ペアの文字数＋真ん中の文字)
void solve() {
    sort(all(S));
    int c = 0, k = 0;
    REP(i, S.size() - 1) {
        c++;
        if (S[i] != S[i + 1]) {
            if (c % 2 == 1) {
                k++;
            }
            c = 0;
        }
    }
    if (c % 2 == 0) {
        k++;
    }

    if (k == 0) {
        cout << S.size() << endl;
    } else {
        cout << 2 * ((S.size() - k)/ (2 * k)) + 1 << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> S;
    
    solve();
    return 0;
}
