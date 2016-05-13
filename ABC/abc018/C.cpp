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

const int MAX_R = 500;
int R, C, K;
string s[MAX_R];
int white_num[MAX_R][MAX_R][2];

// j列の前後(k-1)マスにK-kマス以上白マスがあれば菱形の中央として成立
bool check(int i, int j) {
    FOR(k, -(K - 1), K) {
        if (j + k < 0 || C <= j + k || 
            white_num[i][j + k][0] < K - abs(k) ||
             white_num[i][j + k][1] < K - abs(k)) {
            return false;
        }
    }
    return true;
}

// 各マスが中心として成立するかどうか→縦方向について数え上げる→横方向に判定
void solve() {
    // 各マスについて, そのマスから上下方向にそのマス含め何マスまで連続して白マスがあるか
    REP(i, R) {
        REP(j, C) {
            // 下
            FOR(k, i, R) {
                if (s[k][j] == 'o') {
                    white_num[i][j][0]++;
                } else {
                    break;
                }
            }
            // 上
            RFOR(k, 0, i + 1) {
                if (s[k][j] == 'o') {
                    white_num[i][j][1]++;
                } else {
                    break;
                }
            }
        }
    }

    // 各マスが条件を満たすか判定
    int ans = 0;
    REP(i, R) {
        REP(j, C) {
            if (check(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> R >> C >> K;
    REP(i, R) {
        cin >> s[i];
    }
    
    solve();
    return 0;
}
