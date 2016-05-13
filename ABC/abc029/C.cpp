/*
 * Created by KeigoOgawa on 4/16/16.
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

const int MAX_N = 8;
int N;

void solve() {
    string s = "";
    REP(i, N) {
        s += 'a';
    }

    int t = 0;
    cout << s << endl;
    REP(i, pow(3, N) - 1) {
        int up = 1;
        while (up != 0) {
            if (s[N - up] == 'c') {
                s[N - up] = 'a';
                up++;
            } else if (s[N - up] == 'a') {
                s[N - up] = 'b';
                up = 0;
            } else {
                s[N - up] = 'c';
                up = 0;
            }
        }
        cout << s << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;

    solve();
    return 0;
}
