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

int N, K;
string S;
bool used[100];

// sとtの不一致となる文字数の最小値を返す
int check(string s, string t) {
    sort(all(s));
    sort(all(t));
    int ans = s.size();
    int j = 0, i = 0;
    while (i < s.size() && j < s.size()) {
        if (s[i] < t[j]) {
            i++;
        } else if (s[i] == t[j]) {
            ans--;
            j++;
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

void solve() {
    string t = S;
    sort(all(t));
    // ord[i]: Sのi文字目が何番目に小さいか
    vector<int> ord(S.size());
    fill(all(ord), -1);
    int rank = 0;
    REP(i, t.size()) {
        REP(j, S.size()) {
            if (t[i] == S[j] && ord[j] == -1) {
                ord[j] = rank;
                rank++;
            }
        }
    }

    t = S;
    int sum_k = 0;
    // i文字目を決める
    REP(i, S.size()) {
        // t[i]に追加しようとしている文字の順位とtでのインデックス
        int now = 0, now_index = -1;
        while (used[now]) {
            now++;
        }

        // 不一致がK以内になるような最小の文字を決める
        while (now < S.size()) {
            if (used[now]) {
                now++;
                continue;
            }

            // 順位がnowの文字のインデックスをSから探す
            REP(j, S.size()) {
                if (ord[j] == now) {
                    now_index = j;
                }
            }

            // S[now_index] == t[tind]を探す
            int tind = -1;
            REP(i, t.size()) {
                if (S[now_index] == t[i]) {
                    tind = i;
                }
            }

            // 文字を入れ替えてkを計算
            t[tind] = t[i];
            t[i] = S[now_index];

            int k = check(t.substr(i + 1), S.substr(i + 1));
            if (t[i] != S[i]) {
                k++;
            }

            if (sum_k + k > K) {
                t[i] = t[tind];
                t[tind] = S[now_index];
                now++;
            } else {
                used[now] = true;
                // i文字をこれで決定
                if (t[i] != S[i]) {
                    sum_k++;
                }

                break;
            }
        }
    }

    cout << t << endl;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N >> K;
    cin >> S;

    solve();
    return 0;
}
