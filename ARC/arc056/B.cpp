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

struct edge {
    int to, cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};

const int MAX_N = 2*1e5;
int N, M, S;
int uv[MAX_N][2];
vector<vector<int> > sita(MAX_N);
vector<int> ans;
bool used[MAX_N];

bool check(int i, int s) {
    REP(j, sita[s].size()) {
        if (sita[s][j] == i) {
            return true;
        } else if (sita[sita[s][j]].size() > 0 && sita[s][j] > i && !used[sita[s][j]]) {
            if (check(i, sita[s][j])) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    REP(i, M) {
        int muv = min(uv[i][0], uv[i][1]);
        int Muv = max(uv[i][0], uv[i][1]);
        sita[Muv].push_back(muv);
    }
    REP(i, N) {
        if (check(i, S)) {
            ans.push_back(i);
            used[i] = true;
        }
    }

    ans.push_back(S);
    sort(all(ans));
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    REP(i, ans.size()) {
        cout << ans[i] + 1 << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> S;
    S--;
    REP(i, M) {
        cin >> uv[i][0] >> uv[i][1];
        uv[i][0]--;
        uv[i][1]--;
    }
    
    solve();
    return 0;
}
