// created: 12-27-2025 Sat 10:57 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll qry(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    ll res; cin >> res;
    return res;
}

map<array<int, 2>, ll> cache;

ll cache_qry(int l, int r) {
    array<int, 2> idx{l, r};
    auto it = cache.find(idx);
    if (it == end(cache)) {
        ll res = qry(l, r);
        cache[idx] = res;
        return res;
    } else {
        return it->second;
    }
}

void solve() {
    int n; cin >> n;
    cache.clear();
    int l = 1, r = n;
    ll cur_sum = cache_qry(l, r);
    while (l < r) {
        // binary search on concat point
        int l1 = l, r1 = r;
        while (l1 < r1) {
            int mid = midpoint(l1, r1);
            if (cache_qry(l, mid) > cur_sum / 2)
                r1 = mid;
            else
                l1 = mid + 1;
        }
        int left_elts = l1 - l, right_elts = r - l1 + 1;
        if (left_elts < right_elts) {
            // maximum in left
            cur_sum = cache_qry(l, l1 - 1);
            r = l1 - 1;
        } else {
            // maximum in right
            cur_sum -= cache_qry(l, l1 - 1);
            l = l1;
        }
    }
    cout << "! " << cur_sum << endl;
}

int main() {
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
