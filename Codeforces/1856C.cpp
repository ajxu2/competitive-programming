// created: 08-09-2023 Wed 08:44 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a) cin >> i;
    function<bool(int, int, int)> check = [&](int i, int x, int op) {
        int diff = x - a[i];
        if (diff <= 0) return true;
        if (i == n-1 || op <= 0) return false;
        if (x <= a[i+1] + 1) return op >= diff;
        return check(i+1, x-1, op-diff);
    };
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        bool ok = false;
        for (int i = 0; i < n; i++) ok |= check(i, mid, k);
        if (ok) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
