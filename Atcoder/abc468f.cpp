// created: 07-25-2026 Sat 08:17 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct Segtree {
    int n;
    V<int> tree;
    Segtree(int _n) {
        n = 1;
        while (n < _n)
            n *= 2;
        tree.assign(2 * n, 0);
    }
    void pull(int i) {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    void upd(int i, int v) {
        tree[i += n] = v;
        for (i >>= 1; i > 0; i >>= 1)
            pull(i);
    }
    int qry(int l, int r) {
        l += n, r += n;
        int res = 0;
        while (l <= r) {
            if ((l & 1) == 1)
                res = max(res, tree[l++]);
            if ((r & 1) == 0)
                res = max(res, tree[r--]);
            l >>= 1, r >>= 1;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // dp[i] = max score if var that's not prefix max is i
    Segtree segt(n + 1);
    int ans = 0, cur_max = 0;
    for (int i : a) {
        if (i > cur_max) {
            cur_max = i;
            ans++;
        } else {
            segt.upd(i, segt.qry(0, i - 1) + 1);
        }
    }
    ans += segt.tree[1];
    cout << ans << '\n';
    return 0;
}
