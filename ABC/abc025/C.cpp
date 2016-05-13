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

int a[3][3];
int b[2][3], c[3][2];
// 得点の合計
int sum = 0;

int calcScore() {
    int sa = 0, sb = 0;
    REP(i, 2) {
        REP(j, 3) {
            if (a[i][j] == a[i + 1][j]) {
                sa += b[i][j];
            } else {
                sb += b[i][j];
            }
        }
    }

    REP(i, 3) {
        REP(j, 2) {
            if (a[i][j] == a[i][j + 1]) {
                sa += c[i][j];
            } else {
                sb += c[i][j];
            }
        }
    }
    return sa - sb;
}

int dfs(int n) {
    int maxS = -INF, minS = INF;

    // 置く場所がなかったら得点を計算
    if (n == 9) {
        return calcScore();
    }

    REP(i, 3) {
        REP(j, 3) {
            if (a[i][j] == 0) {
                // まだ置いていないマスに対して, ○か×を手番に応じて置く
                if (n % 2 == 0) {
                    a[i][j] = 1;
                    maxS = max(maxS, dfs(n + 1));
                } else {
                    a[i][j] = -1;
                    minS = min(minS, dfs(n + 1));
                }
                a[i][j] = 0;
            }
        }
    }

    // Aの手番のときは最大値, Bのときは最小値を返す
    if (n % 2 == 0) {
        return maxS;
    } else {
        return minS;
    }
}

// A, Bの得点の合計値は一定
// Aは, score = (score A) - (score B) を最大化
// Bは, score = (score A) - (score B) を最小化
// するように行動すると考える

// 1. 現時点で置き場がないならscoreを計算
// 2. すべての置き場所に対し置く
// 3. おいた後にscoreを再帰計算
// 4. Aの手番なら最大値, Bなら最小値を返す

void solve() {
    // diff = sa - sb
    int diff = dfs(0);
    int score_a = (diff + sum) / 2;
    int score_b = sum - score_a;

    cout << score_a << endl;
    cout << score_b << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, 2) {
        REP(j, 3) {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }

    REP(i, 3) {
        REP(j, 2) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    solve();
    return 0;
}
