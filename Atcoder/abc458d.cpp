// created: 05-16-2026 Sat 08:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x; cin >> x;
    indexed_set<pair<int, int>> s;
    s.insert({x, -1});
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        s.insert({a, 2 * i});
        s.insert({b, 2 * i + 1});
        auto it = s.find_by_order(i + 1);
        cout << it->first << '\n';
    }
    return 0;
}
