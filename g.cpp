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

int H, W, K, si, sj, A[50][50];
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};
bool inner(int x, int y) { return 0 <= x && x < H && 0 <= y && y < W; }
bool inner(pr &r) { return inner(r.first, r.second); }
pr next(int x, int y, int k) { return make_pair(x + dx[k], y + dy[k]); }
pr next(pr &r, int k) { return next(r.first, r.second, k); }

ll dp[2501][50][50];

int main() {
    cin >> H >> W >> K >> si >> sj;
    --si, --sj;
    fill(dp[0][0], dp[2501][0], -1e18);
    dp[0][si][sj] = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) cin >> A[i][j];

    for (int t = 0; t < 2500; ++t) {
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j) {
                for (int k = 0; k < 5; ++k) {
                    auto [ni, nj] = next(i, j, k);
                    if (!inner(ni, nj)) continue;
                    chmax(dp[t + 1][ni][nj], dp[t][i][j] + A[ni][nj]);
                }
            }
    }

    if (K <= 2500) {
        ll ans = 0;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j) chmax(ans, dp[K][i][j]);
        cout << ans << '\n';
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            chmax(ans, dp[2500][i][j] + ll(K - 2500) * A[i][j]);

    cout << ans << '\n';
}
