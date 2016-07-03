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

int H, W;
string s[100];
int a[100][100];
const int dir[8+1]={0,-1,-1,0,1,-1,1,1,0};

void fillWhite(int i, int j) {
    REP(k, 8) {
        int xx = i + dir[k], yy = j + dir[k + 1];
        if (xx >= 0 && xx < H && 0<= yy && yy < W) {
            a[xx][yy] = 1;
        }
    }
    a[i][j] = 1;
}

bool check(int i, int j) {
    REP(k, 8) {
        int xx = i + dir[k], yy = j + dir[k + 1];
        if (xx >= 0 && xx < H && 0<= yy && yy < W) {
            if (a[xx][yy] == 0) {
                return true;
            }
        }
    }
    if (a[i][j] == 0) {
        return true;
    }
    return false;
}

void solve() {
    REP(i, H) {
        REP(j, W) {
            if (s[i][j] == '.') {
                fillWhite(i, j);
            }
        }
    }

    REP(i, H) {
        REP(j, W) {
            if (s[i][j] == '#') {
                if (!check(i, j)) {
                    cout << "impossible\n";
                    return;
                }   
            }
        }
    }

    cout << "possible\n";
    REP(i, H) {
        REP(j, W) {
            if (a[i][j] == 0) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i, H) {
        cin >> s[i];
    }
    
    solve();
    return 0;
}
