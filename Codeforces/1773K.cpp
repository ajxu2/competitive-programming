// created: 01-27-2023 Fri 11:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    if (n == 1 && k == 1) { // goofy ahh corner case
        cout << "YES\n0\n";
        return 0;
    } else if (n == k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    V<array<int, 2>> ans;
    if (k % 2 == 0) {
        // reduce to (n-k+2, 2)
        for (int i = 1; i < n-k+2; i++) ans.push_back({i, i+1});
        for (int i = n-k+3; i < n; i += 2) {
            ans.push_back({i, i+1});
            for (int j = 1; j < i; j++) ans.push_back({i, j});
        }
    } else {
        // reduce to (n-k+1, 1)
        if (n-k+1 == 2) ans.push_back({1, 2});
        else {
            for (int i = 1; i < n-k+1; i++) ans.push_back({i, i+1});
            ans.push_back({1, n-k+1});
        }
        for (int i = n-k+2; i < n; i += 2) {
            ans.push_back({i, i+1});
            for (int j = 1; j < i; j++) ans.push_back({i, j});
        }
    }
    cout << ans.size() << "\n";
    for (array<int, 2> i : ans) cout << i[0] << " " << i[1] << "\n";
    return 0;
}
