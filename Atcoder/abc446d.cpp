// created: 02-23-2026 Mon 01:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    map<int, V<int>> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]].push_back(i);
    V<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        if (!mp.contains(a[i] + 1))
            continue;
        const V<int>& v = mp[a[i] + 1];
        auto it = lower_bound(begin(v), end(v), i);
        if (it == end(v))
            continue;
        int nxt = *it;
        dp[nxt] = max(dp[nxt], dp[i] + 1);
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
