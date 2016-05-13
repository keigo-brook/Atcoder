/*
 * Created by KeigoOgawa
 * 最短経路, ワーシャルフロイド  
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
const int MAX_V = 10;

// d[u][v]は辺(u,v)のコスト(存在しない場合はINF,ただしd[i][i]=0)となる。
int d[MAX_V][MAX_V];
int V;

// 各頂点同士の最短経路を求めるO(N^3)
void warshall_floyd() {
    REP(k, V) {
        REP(i, V) {
            REP(j, V) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

// 最短経路が2のものを列挙する
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    V = N;
    fill(d[0], d[V], INF);
    REP(i, V) {
        d[i][i] = 0;
    }

    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a][b] = d[b][a] = 1;
    }

    warshall_floyd();
    REP(i, N) {
        int ans = 0;
        REP(j, N) {
            if (d[i][j] == 2) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
