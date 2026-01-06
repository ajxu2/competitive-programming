// created: 01-05-2026 Mon 03:36 PM

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
        tree.assign(2 * n, {0, -1});
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
    void add_at_node(int v, Line line) {
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
    void add_segment(int v, Line line, int ll, int rr) {
        if (rr <= l[v] || r[v] <= ll)
            return;
        if (ll <= l[v] && r[v] <= rr) {
            add_at_node(v, line);
        } else {
            add_segment(2 * v, line, ll, rr);
            add_segment(2 * v + 1, line, ll, rr);
        }
    }
    void add_segment(Line line, int ll, int rr) {
        add_segment(1, line, ll, rr);
    }
    ll qry(int x) {
        ll ans = -INF;
        for (int i = x + n; i >= 1; i /= 2)
            ans = max(ans, tree[i](x));
        return ans;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    LiChao lichao(m + 1);
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll slope = (y2 - y1) / (x2 - x1);
        Line line = {slope, y1 - slope * x1};
        lichao.add_segment(line, x1, x2 + 1);
    }
    for (int i = 0; i <= m; i++)
        cout << lichao.qry(i) << " \n"[i == m];
    return 0;
}
