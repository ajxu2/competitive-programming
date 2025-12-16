// created: 12-16-2025 Tue 11:44 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;
struct Line {
    ll a, b;
    ll operator()(ll x) { return a * x + b; }
};

struct LiChao {
    int n;
    V<Line> tree;
    LiChao(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, {0, INF});
    }
    void add(Line line) {
        int v = 1, l = 0, r = n;
        for (;;) {
            Line old = tree[v];
            int mid = midpoint(l, r);
            if (old(mid) < line(mid))
                swap(old, line); // ensure new line lower on majority
            tree[v] = line;
            if (r - l == 1)
                break;
            if (old(l) < line(l)) // intersection on left
                v = 2 * v, r = mid;
            else // intersection on right
                v = 2 * v + 1, l = mid;
            line = old;
        }
    }
    ll qry(int x) {
        ll res = INF;
        for (int i = x + n; i >= 1; i /= 2)
            res = min(res, tree[i](x));
        return res;
    }
};

const int MX = 1'000'000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    V<int> s(n), f(n);
    for (int& i : s)
        cin >> i;
    for (int& i : f)
        cin >> i;
    LiChao lichao(MX + 1);
    lichao.add({x, 0});
    V<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = lichao.qry(s[i]);
        lichao.add({f[i], dp[i]});
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
