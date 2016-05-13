//
// Created by KeigoOgawa on 1/7/16.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int n;

void solve() {
    ll a[] = {0, 0, 1}, tmp;
    for (int i = 3; i < n; ++i) {
        tmp = a[0] + a[1] + a[2];
        a[i % 3] = tmp%10007;
    }
    printf("%lld\n", a[(n-1)%3]);
}

int main(void) {
    scanf("%d", &n);
    solve();
    return 0;
}
