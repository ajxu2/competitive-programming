// created: 04-09-2026 Thu 01:16 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll INF = 1e18;

struct LazySeg { // range add, range max
    int n;
    V<ll> tree, lazy;
    // rpeng way: lazy stores updates *to be propagated to children*
    V<int> lb, rb;
    LazySeg(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
        lb.resize(2 * n);
        rb.resize(2 * n);
        for (int i = 0; i < n; i++) {
            lb[i + n] = i;
            rb[i + n] = i + 1;
        }
        for (int i = n - 1; i >= 1; i--) {
            lb[i] = lb[2 * i];
            rb[i] = rb[2 * i + 1];
        }
    }
    void push(int i) {
        if (i < n) {
            lazy[2 * i] += lazy[i];
            tree[2 * i] += lazy[i];
            lazy[2 * i + 1] += lazy[i];
            tree[2 * i + 1] += lazy[i];
        }
        lazy[i] = 0;
    }
    void pull(int i) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    void range_add(int i, int l, int r, ll v) {
        if (r <= lb[i] || rb[i] <= l)
            return;
        if (l <= lb[i] && rb[i] <= r) {
            lazy[i] += v;
            tree[i] += v;
            return;
        }
        push(i);
        range_add(2 * i, l, r, v);
        range_add(2 * i + 1, l, r, v);
        pull(i);
    }
    void range_add(int l, int r, ll v) {
        range_add(1, l, r, v);
    }
    ll range_max(int i, int l, int r) {
        if (r <= lb[i] || rb[i] <= l)
            return -INF;
        if (l <= lb[i] && rb[i] <= r)
            return tree[i];
        push(i);
        return max(range_max(2 * i, l, r), range_max(2 * i + 1, l, r));
    }
    ll range_max(int l, int r) {
        return range_max(1, l, r);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<array<int, 3>> a(m);
    for (auto& [l, r, v] : a)
        cin >> l >> r >> v, l--;
    // dp[i] = max score if char i is 1, past that 0
    V<V<int>> b(n + 1); // i for adding interval i, ~i for subtracting
    for (int i = 0; i < m; i++) {
        b[a[i][0]].push_back(i);
        b[a[i][1]].push_back(~i);
    }
    LazySeg lzseg(n);
    ll cur_v = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j : b[i]) {
            if (j >= 0) {
                // add interval
                lzseg.range_add(0, i, a[j][2]);
                cur_v += a[j][2];
            } else {
                // remove interval
                lzseg.range_add(0, a[~j][0], -a[~j][2]);
                cur_v -= a[~j][2];
            }
        }
        ll res = max(cur_v, lzseg.range_max(0, i));
        lzseg.range_add(i, i + 1, res);
        ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}
