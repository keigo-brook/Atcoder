// imos法

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
typedef pair<int, int> P;

const int MAX_N = 200000;
const int MAX_Q = 200000;

int N, Q;
vector<P> vp;
int n[MAX_N];

void solve() {
    REP(i, Q) {
        n[vp[i].first]++;
        n[vp[i].second]--;
    }

    int sum = 0;
    REP(i, N) {
        sum += n[i];
        printf("%d", sum % 2);
    }
    printf("\n");
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    REP(i, Q) {
        int l, r;
        cin >> l >> r;
        vp.push_back(make_pair(l-1, r));
    }
    solve();
    return 0;
}