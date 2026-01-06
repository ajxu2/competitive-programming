// created: 01-06-2026 Tue 10:24 AM

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
            r[i + n] = i;
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
        if (rr < l[v] || r[v] < ll)
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
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    stack<int> stk;
    V<int> l(n), r(n); // nearest smaller element to left and right
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[i] <= a[stk.top()])
            stk.pop();
        l[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    while (!stk.empty())
        stk.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] <= a[stk.top()])
            stk.pop();
        r[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    for (int i = 0; i < n; i++)
        l[i]++; // convert (l[i], r[i]) into half open intervals
    LiChao lichao(n + 1);
    for (int i = 0; i < n; i++) {
        int len = r[i] - l[i];
        if (len >= k) {
            lichao.add_segment({a[i], (ll)(-a[i]) * (l[i] - k)}, l[i] - k, l[i]);
            lichao.add_segment({0, (ll)a[i] * k}, l[i], r[i] - k);
            lichao.add_segment({-a[i], (ll)a[i] * r[i]}, r[i] - k, r[i]);
        } else {
            lichao.add_segment({a[i], (ll)(-a[i]) * (l[i] - k)}, l[i] - k, r[i] - k);
            lichao.add_segment({0, (ll)a[i] * len}, r[i] - k, l[i]);
            lichao.add_segment({-a[i], (ll)a[i] * r[i]}, l[i], r[i]);
        }
    }
    for (int i = 0; i <= n - k; i++)
        cout << lichao.qry(i) << " \n"[i == n - k];
    return 0;
}
