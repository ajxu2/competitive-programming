// created: 12-28-2025 Sun 11:10 AM

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
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    indexed_set<array<int, 2>> se;
    V<int> num_greater(n);
    // num_greater[i] = number of elements to the left of i and > a[i]
    for (int i = 0; i < n; i++) {
        num_greater[i] = i - se.order_of_key({a[i], INF});
        se.insert({a[i], i});
    }
    for (int& i : num_greater)
        i = max(i - k, 0);
    map<int, V<int>> ranks;
    for (int i = 0; i < n; i++)
        ranks[a[i]].push_back(num_greater[i]);
    for (auto& [_, v] : ranks)
        sort(begin(v), end(v));
    indexed_set<int> remaining;
    for (int i = 0; i < n; i++)
        remaining.insert(i);
    V<int> ans(n);
    for (auto [x, v] : ranks) {
        for (int i : v) {
            auto it = remaining.find_by_order(i);
            ans[*it] = x;
            remaining.erase(it);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
    return 0;
}
