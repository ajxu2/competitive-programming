// created: 11-16-2025 Sun 10:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    indexed_set<array<int, 2>> se;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int num_greater = i - se.order_of_key({a[i], INF});
        ans = max(ans, num_greater);
        se.insert({a[i], i});
    }
    cout << ans << '\n';
    return 0;
}
