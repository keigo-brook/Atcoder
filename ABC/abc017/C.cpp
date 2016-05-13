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

const int MAX_N = 100000;
int N, M;
int stone_count[MAX_N];
int stone_score[MAX_N];

void solve() {
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    int sum = 0;
    REP(i, N) {
        int l, r, s;
        cin >> l >> r >> s;
        l--; r--;
        sum += s;
        FOR(j, l, r + 1) {
            stone_count[j]++;
            stone_score[j] += s;
        }
    }
    // 1~Mについてそれぞれ何個かとその石のスコアの合計点を数える
    // M個の宝石のうちどれを外すかを考える
    // その宝石を外す→その宝石が手に入る遺跡分の点数を合計から減らす
    int ans = 0;
    REP(i, M) {
        if (stone_count[i] > 0) {
            ans = max(ans, sum - stone_score[i]);
        } else {
            ans = sum;
        }
    }

    cout << ans << endl;
    return 0;
}
