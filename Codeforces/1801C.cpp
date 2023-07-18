// created: 07-13-2023 Thu 10:40 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n; cin >> n;
    V<V<int>> a(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        int mx = 0;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            if (x > mx) {
                mx = x; a[i].push_back(x);
            }
        }
    }
    // sort by back
    sort(a.begin(), a.end(), [](const V<int>& a, const V<int>& b) { return a.back() < b.back(); });
    map<int, int> dp; // dp[i] = score if max element at most i
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < sz(a[i]); j++) {
            auto it = dp.lower_bound(a[i][j]);
            if (it == dp.begin()) mx = max(mx, sz(a[i]) - j);
            else {
                it--;
                mx = max(mx, sz(a[i]) - j + (*it).second);
            }
        }
        if (dp.count(a[i].back())) dp[a[i].back()] = max(dp[a[i].back()], mx);
        else dp[a[i].back()] = mx;
    }
    cout << (*dp.rbegin()).second << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
