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

const int MOD = 1e9 + 7;
const int MAX_P = 200000;

// n! mod p のテーブル O(p)
ll fact[MAX_P];

void init_fact() {
    fact[0] = 1;
    FOR(i, 1, MAX_P) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// ax + by = gcd(a, b)を返す
// x, yは整数解になっている
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

// ax ≡ 1(mod m) となるxを返す
ll mod_inverse(ll a, ll m) {
    ll x, y;
    // x, yがax + my = 1 の解になっている
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

// n! = a*p^e としたときの a mod p, e を求める. O(log_p n)
// e = (n!の中にあるpの数) => n!からpを取り出した残りがa, つまり,
// a = (pで割り切れないものの積) * (pで割り切れるものをpで割った商)
// よって, (n! mod p) = (a mod p) となる
ll mod_fact(ll n, ll p, ll &e) {
    e = 0;
    if (n == 0) {
        return 1;
    }

    // pの倍数の部分を計算
    ll res = mod_fact(n / p, p, e);
    e += n / p;

    // (p-1)! ≡ -1 より (p-1)!^(n/p)は n/p の偶奇だけで計算できる
    if (n / p % 2 != 0) {
        return res * (p - fact[n % p] % p);
    }
    return res * fact[n % p] % p;
}

ll mod_comb(ll n, ll k, ll p) {
    if (n < 0 || k < 0 || n < k) {
        return 0;
    }
    ll e1, e2, e3;
    ll a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n - k, p, e3);

    if (e1 > e2 + e3) {
        return 0;
    }
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int H, W, A, B;

void solve() {
  ll ans = 0;
  REP(i, H - A - 1) {
    ll a = mod_comb(B - 1 + i, i, MOD) % MOD;
    ll b = mod_comb(H - i - 1 + (W - B - 1), W - B - 1, MOD) % MOD;
    ans += (a * b) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  init_fact();
  cin >> H >> W >> A >> B;
  A--;

  solve();
  return 0;
}
