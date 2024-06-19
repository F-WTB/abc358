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

int N, M, a[10];

string S;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> S;
        for (int j = 0; j < M; ++j)
            if (S[j] == 'o')
                a[i] |= 1 << j;
    }

    int ans = M;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int x = 0;
        for (int i = 0; i < N; ++i)
            if (bit & (1 << i))
                x |= a[i];
        if (x == (1 << M) - 1)
            chmin(ans, __builtin_popcountll(bit));
    }
    cout << ans << '\n';
}
