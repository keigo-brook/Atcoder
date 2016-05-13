/*
 * Created by KeigoOgawa on 4/4/16.
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

int deg, dis;

string direction(int deg) {
    deg *= 10;
    if (deg < 1125) {
        return "N";
    } else if (deg < 3375) {
        return "NNE";
    } else if (deg < 5625) {
        return "NE";
    } else if (deg < 7875) {
        return "ENE";
    } else if (deg < 10125) {
        return "E";
    } else if (deg < 12375) {
        return "ESE";
    } else if (deg < 14625) {
        return "SE";
    } else if (deg < 16875) {
        return "SSE";
    } else if (deg < 19125) {
        return "S";
    } else if (deg < 21375) {
        return "SSW";
    } else if (deg < 23625) {
        return "SW";
    } else if (deg < 25875) {
        return "WSW";
    } else if (deg < 28125) {
        return "W";
    } else if (deg < 30375) {
        return "WNW";
    } else if (deg < 32625) {
        return "NW";
    } else if (deg < 34875) {
        return "NNW";
    } else {
        return "N";
    }
}

int power(int dis) {
    dis *= 10;
    int p = round(dis / 60.0);
    if (p <= 2) {
        return 0;
    } else if (p <= 15) {
        return 1;
    } else if (p <= 33) {
        return 2;
    } else if (p <= 54) {
        return 3;
    } else if (p <= 79) {
        return 4;
    } else if (p <= 107) {
        return 5;
    } else if (p <= 138) {
        return 6;
    } else if (p <= 171) {
        return 7;
    } else if (p <= 207) {
        return 8;
    } else if (p <= 244) {
        return 9;
    } else if (p <= 284) {
        return 10;
    } else if (p <= 326) {
        return 11;
    } else {
        return 12;
    }
}

void solve() {
    int p = power(dis);
    string d = direction(deg);

    if (p == 0) {
        cout << "C 0" << endl;
    } else {
        cout << d << ' ' << p << endl;
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> deg >> dis;

    solve();
    return 0;
}
