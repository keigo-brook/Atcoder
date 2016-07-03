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
#include <string>

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

const int MAX_N = 50;
const int MAX_K = 9;
int K, N;
vector<pair<int, string> > vw(MAX_N);
vector<string> ans;
int len[MAX_K + 1];

bool check() {
    REP(i, N) {
        int n = vw[i].first;
        string s = vw[i].second;
        while (n > 0) {
            // len[t]だけ文字列から削除する
            int t = n % 10;
            // 数字が残っているのに文字がなくなったら矛盾
            if ((int)s.size() - len[t] < 0) {
                return false;
            }
            ans[t] = s.substr(s.size() - len[t]);
            s.erase(s.end() - len[t], s.end());
            n /= 10;
        }

        // 文字がないのに数字が残っていたら矛盾
        if (s.size() > 0) {
            return false;
        }
    }
    return true;
}

bool dfs(int n, int i) {
    if (n == K + 1) {
        return check();
    }
    len[n] = i;
    FOR(j, 1, 4) {
        if(dfs(n + 1, j)) {
            return true;
        }
    }
    return false;
}

// 数字に対応する文字の長さを固定すると, ans[i]は一意に定まるか, 矛盾が生じる
void solve() {
    sort(all(vw));
    dfs(0, 0);
    FOR(i, 1, K + 1) {
        cout << ans[i] << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> K >> N;
    vw.resize(N);
    ans.resize(K + 1);
    REP(i, N) {
        cin >> vw[i].first >> vw[i].second;
    }
    
    solve();
    return 0;
}
