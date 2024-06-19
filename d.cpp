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

int N, M, A[200000], B[200000];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A, A + N);
    for (int i = 0; i < M; ++i)
        cin >> B[i];

    sort(B, B + M);

    ll ans = 0;
    for (int i = 0, j = 0; i < M; ++i) {
        while (j < N && A[j] < B[i])
            ++j;
        if (j >= N) {
            cout << -1 << '\n';
            return 0;
        }
        ans += A[j];
        ++j;
    }
    cout << ans << '\n';
}
