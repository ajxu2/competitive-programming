// created: 05-19-2025 Mon 01:56 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // process queries in decreasing order of left endpoint and use stack
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<V<array<int, 2>>> qs(n); // qs[i] = queries at left endpoint
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        qs[l].push_back({r, i});
    }
    V<int> ans(q);
    V<int> stk; // smallest at top
    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && a[i] >= a[stk.back()])
            stk.pop_back();
        stk.push_back(i);
        for (auto [r, idx] : qs[i])
            ans[idx] = upper_bound(rbegin(stk), rend(stk), r) - rbegin(stk);
    }
    for (int i : ans)
        cout << i << '\n';
    return 0;
}
