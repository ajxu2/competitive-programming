// created: 01-05-2026 Mon 03:34 PM

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
    V<int> l, r;
    LiChao(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, {0, -INF});
        l.resize(2 * n);
        r.resize(2 * n);
        for (int i = 0; i < n; i++) {
            l[i + n] = i;
            r[i + n] = i + 1;
        }
        for (int i = n - 1; i >= 1; i--) {
            l[i] = l[2 * i];
            r[i] = r[2 * i + 1];
        }
    }
    void add(Line line) {
        int v = 1;
        for (;;) {
            Line old = tree[v];
            int mid = midpoint(l[v], r[v]);
            if (old(mid) > line(mid))
                swap(old, line);
            tree[v] = line;
            if (v >= n)
                break;
            v *= 2;
            if (old(l[v]) < line(l[v]))
                v++;
            line = old;
        }
    }
    ll qry(int x) {
        ll ans = -INF;
        for (int i = x + n; i >= 1; i /= 2)
            ans = max(ans, tree[i](x));
        return ans;
    }
};

const int MAX = 100'000;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    LiChao lichao(MAX + 1);
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            lichao.add({a, b});
        } else {
            int x; cin >> x;
            cout << lichao.qry(x) << '\n';
        }
    }
    return 0;
}
