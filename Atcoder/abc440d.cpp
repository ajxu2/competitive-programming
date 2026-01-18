// created: 01-15-2026 Thu 03:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    ordered_set<int> oset(begin(a), end(a));
    while (q--) {
        int x, y; cin >> x >> y;
        int l = x, r = 2e9 + 5;
        int thing = oset.order_of_key(x);
        while (l < r) {
            int mid = midpoint(l, r);
            int cnt = (mid - x + 1) - (oset.order_of_key(mid + 1) - thing);
            if (cnt < y)
                l = mid + 1;
            else
                r = mid;
        }
        cout << l << '\n';
    }
    return 0;
}
