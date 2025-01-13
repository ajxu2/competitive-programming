// created: 01-09-2025 Thu 05:53 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

struct BIT {
    int n;
    V<ll> tree;
    BIT(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void add(int i, ll v) {
        for (; i < n; i |= i + 1) tree[i] += v;
    }
    ll qry(int i) {
        ll res = 0;
        for (; i >= 0; i &= i + 1, i--) res += tree[i];
        return res;
    }
    ll qry(int l, int r) { return qry(r) - qry(l-1); }
    int lower_bound(ll x) {
        // first i such that bit.qry(i) >= x
        int res = -1;
        ll sum = 0;
        for (int i = 30; i >= 0; i--) {
            int nx = res + (1 << i);
            if (nx < n && sum + tree[nx] < x) {
                res = nx;
                sum += tree[nx];
            }
        }
        return res + 1;
    }
    int upper_bound(ll x) {
        // first i such that bit.qry(i) > x
        return lower_bound(x + 1);
    }
};

const int BIG = 1e9;

void solve() {
    // binary search on answer
    // for each candidate, we can check if it is possible
    // by brute forcing over where we place the vertical line
    // and seeing if there's any place we can place the horizontal line
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (array<int, 2>& i : a) cin >> i[0] >> i[1];
    // coordinate compress
    V<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        xs[i] = a[i][0];
        ys[i] = a[i][1];
    }
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    for (array<int, 2>& i : a) {
        i[0] = lower_bound(begin(xs), end(xs), i[0]) - begin(xs);
        i[1] = lower_bound(begin(ys), end(ys), i[1]) - begin(ys);
    }
    V<V<int>> aa(ssize(xs)); // y-coordinates based on x-coordinate
    for (array<int, 2> i : a) aa[i[0]].push_back(i[1]);
    // function to test if we can have all four >= x
    auto check = [&](int x) -> array<int, 2> {
        if (x == 0) return {0, 0};
        BIT bitl(n), bitr(n);
        int cntl = 0, cntr = n;
        for (array<int, 2> i : a) bitr.add(i[1], 1);
        for (int i = 0; i < ssize(xs); i++) {
            for (int j : aa[i]) {
                bitl.add(j, 1); cntl++;
                bitr.add(j, -1); cntr--;
            }
            int l1 = bitl.lower_bound(x) + 1;
            int r1 = bitl.upper_bound(cntl - x);
            int l2 = bitr.lower_bound(x) + 1;
            int r2 = bitr.upper_bound(cntr - x);
            if (l1 <= r1 && l2 <= r2 && l2 <= r1 && l1 <= r2) {
                // intervals intersect yay
                if (l1 <= l2) {
                    if (r1 <= r2) return {i + 1, r1};
                    else return {i + 1, r2};
                } else {
                    if (r2 <= r1) return {i + 1, r2};
                    else return {i + 1, r1};
                }
            }
        }
        return {-1, -1};
    };
    int l = 0, r = n / 4;
    while (l < r) {
        // find last true
        int mid = midpoint(l, r + 1);
        array<int, 2> res = check(mid);
        if (res[0] == -1) r = mid - 1;
        else l = mid;
    }
    cout << l << '\n';
    array<int, 2> ans = check(l);
    ans[0] = ans[0] >= ssize(xs) ? BIG : xs[ans[0]];
    ans[1] = ans[1] >= ssize(ys) ? BIG : ys[ans[1]];
    cout << ans[0] << ' ' << ans[1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
