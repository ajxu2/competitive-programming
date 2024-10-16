// created: 10-15-2024 Tue 05:58 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct BIT {
    V<ll> tree;
    BIT(int n) {
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        for (; i < ssize(tree); i |= i + 1) tree[i] += v;
    }
    ll qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    ll qry(int l, int r) { return qry(r) - qry(l - 1); }
};

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) { cin >> i; i--; }
    V<int> segs(2 * n, -1);
    for (int i = 0; i < n; i++) {
        if (i > a[i]) segs[a[i] + n] = i;
        else {
            segs[a[i]] = i;
            segs[a[i] + n] = i + n;
        }
    }
    BIT bit(2 * n);
    V<int> ans(n, -1);
    for (int i = 0; i < 2 * n; i++) {
        if (segs[i] == -1) continue;
        ans[i % n] = i - segs[i] - bit.qry(segs[i], i);
        bit.add(segs[i], 1);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
