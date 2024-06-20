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

int N, M, K;
char g[201][201];

int x = 0, y;

void f(int a, int b) {
    g[a + x + 1][b + y + 1] = '.';
    x = a, y = b;
    --K;
}

int d() {
    return N - 1 - x;
}

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
map<char, int> mp{{'U', 2}, {'L', 3}, {'D', 0}, {'R', 1}};
pr next(int x, int y, int k) { return make_pair(x + dx[k], y + dy[k]); }
pr next(pr &r, int k) { return next(r.first, r.second, k); }

void f(char c) {
    auto [nx, ny] = next(x, y, mp[c]);
    f(nx, ny);
}

void f(string s) {
    for (char c : s)
        f(c);
}

void initialize() {
    fill(g[0], g[N * 2 + 1], '+');
    g[0][M * 2 - 1] = 'S';
    g[N * 2][M * 2 - 1] = 'G';

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            g[i * 2 + 1][j * 2 + 1] = 'o';

    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < M; ++j)
            g[i * 2 + 2][j * 2 + 1] = '-';

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M - 1; ++j)
            g[i * 2 + 1][j * 2 + 2] = '|';
}

void output() {
    for (int i = 0; i < N * 2 + 1; ++i) {
        for (int j = 0; j < M * 2 + 1; ++j)
            cout << g[i][j];
        cout << '\n';
    }
};

int main() {
    cin >> N >> M >> K;
    y = M - 1;
    if (K < N || (K - N) & 1) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    initialize();

    --K;

    if (M == 1) {
        for (int i = 0; i < N - 1; ++i) f('D');
        output();
        return 0;
    }
    if (N & 1) {
        int t = min(K - (N - 3), M * 3 - !(M & 1) - 1) - 2;
        for (int i = 0; i < t / 6; ++i) f("DLUL");
        f('D');
        for (int i = 0; i < (t % 6) / 2; ++i) f('L');
        f('D');
        for (int i = 0; i < (t % 6) / 2; ++i) f('R');
        for (int i = 0; i < t / 6; ++i) f("RR");

    } else {
        int t = min(K - N + 2, M * 2 - 1) - 1;
        for (int i = 0; i < t / 2; ++i) f('L');
        f('D');
        for (int i = 0; i < t / 2; ++i) f('R');
    }
    while (d()) {
        int t = min(M * 2, K - d() + 2) - 2;
        f('D');
        for (int i = 0; i < t / 2; ++i) f('L');
        f('D');
        for (int i = 0; i < t / 2; ++i) f('R');
    }
    output();
}
