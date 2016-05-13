/*
 * Created by KeigoOgawa
 * BFS
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

// 右, 上, 左, 下
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_RC = 50;

int R, C, s[2], g[2];
vector<string> c;
int d[MAX_RC][MAX_RC];

int solve() {
    queue<PII>que;

    REP(i, R) {
        REP(j, C) {
            d[i][j] = INF;
        }
    }

    que.push(PII(s[0], s[1]));
    d[s[0]][s[1]] = 0;

    while (!que.empty()) {
        PII p = que.front(); que.pop();
        if (p.first == g[0] && p.second == g[1]) {
            break;
        }

        REP(i, 4) {
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if (0 <= nx && nx < R && 0 <= ny && ny < C && c[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(PII(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[g[0]][g[1]];
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> R >> C;
    cin >> s[0] >> s[1];
    cin >> g[0] >> g[1];
    s[0]--; s[1]--;
    g[0]--; g[1]--;

    c.resize(R);
    REP(i, R) {
        c[i].resize(C + 1);
        cin >> c[i];
    }
    cout << solve() << endl;
    return 0;
}
