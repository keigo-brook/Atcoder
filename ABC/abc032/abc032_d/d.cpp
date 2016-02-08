#include <iostream>
#include <algorithm>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long ll;

const int MAX_N = 200;
int n1;
ll W1;
ll w1[MAX_N], v1[MAX_N];

ll rec1(ll i, ll j) {
    ll res;

    if (i == n1) {
        // 品物残りなし
        res = 0;
    } else if (j < w1[i]) {
        // この品物は入らない
        res = rec1(i + 1, j);
    } else {
        // 入れない場合と入れる場合を両方試す
        res = MAX(rec1(i + 1, j), rec1(i + 1, j - w1[i]) + v1[i]);
    }
    return res;
}


int main(void) {
    cin >> n1 >> W1;
    for (int i = 0; i < n1; ++i) {
        cin >> v1[i] >> w1[i];
    }

    if (n1 <= 30 || W1 > 10000) {
        printf("%lld\n", rec1(0, W1));
    } else {
        int dp[MAX_N + 1][W1 + 1];
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = 0; j <= W1; j++) {
                if (j < w1[i]) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = MAX(dp[i + 1][j], dp[i + 1][j - w1[i]] + v1[i]);
                }
            }
        }
        printf("%d\n", dp[0][W1]);        
    }

    return 0;
}

