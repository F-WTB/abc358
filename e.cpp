#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

int K, C[26];

mint f[1001] = {1}, dp[1001][1001] = {1};

int main() {
    for (int i = 0; i < 1000; ++i)
        f[i + 1] = f[i] * (i + 1);

    cin >> K;
    for (int i = 0; i < 26; ++i) cin >> C[i];

    for (int i = 0; i < 26; ++i) {
        for (int x = 0; x < K + 1; ++x)
            for (int t = 0; t < C[i] + 1; ++t) {
                if (x + t > K) continue;
                dp[i + 1][x + t] += dp[i][x] / f[t];
            }
    }

    mint ans = 0;
    for (int i = 1; i < K + 1; ++i)
        ans += dp[26][i] * f[i];
    cout << ans << '\n';
}
