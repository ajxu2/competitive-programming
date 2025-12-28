// created: 12-27-2025 Sat 09:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    if (k > n / 2) {
        cout << "-1\n";
        return;
    }
    sort(begin(a), end(a));
    V<array<int, 2>> ans;
    if (k == 0) {
        int ptr = n - 2;
        ll sum = a[n - 2][0];
        while (ptr > 0 && sum < a[n - 1][0]) {
            sum += a[--ptr][0];
        }
        if (sum < a[n - 1][0]) {
            cout << "-1\n";
            return;
        }
        for (int i = 0; i < ptr; i++)
            ans.push_back({a[i][1], a[i + 1][1]});
        for (int i = ptr; i < n - 1; i++)
            ans.push_back({a[i][1], a[n - 1][1]});
    } else {
        int thing = n - 2 * (k - 1);
        for (int i = 0; i < thing - 1; i++)
            ans.push_back({a[i + 1][1], a[i][1]});
        for (int i = thing; i < n; i += 2)
            ans.push_back({a[i + 1][1], a[i][1]});
    }
    cout << ssize(ans) << '\n';
    for (auto [u, v] : ans)
        cout << u + 1 << ' ' << v + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
