// created: 09-18-2023 Mon 09:32 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if (n < k || x < k-1) {
        cout << "-1\n";
        return;
    }
    if (x == k) x = k-1;
    cout << (k-1)*k/2 + x*(n-k) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
