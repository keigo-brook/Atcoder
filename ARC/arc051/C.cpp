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

const int MOD = 1e9 + 7;

int N;
ll A, B;
std::priority_queue<ll, std::vector<ll>, std::greater<ll> > que;

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << endl;
        q.pop();
    }
}

void solve() {
    REP(i, B) {
        ll t = que.top() * A;
        que.pop();
        que.push(t);
    }
    print_queue(que);
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        que.push(tmp);
    }
    solve();
    return 0;
}
