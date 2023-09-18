// created: 09-18-2023 Mon 10:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<int> l(k+1), r(k+1);
    int ptr = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        while (ptr <= mx) {
            l[ptr] = i;
            ptr++;
        }
    }
    ptr = 0, mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mx = max(mx, a[i]);
        while (ptr <= mx) {
            r[ptr] = i;
            ptr++;
        }
    }
    V<bool> in(k+1, 0);
    for (int i : a) in[i] = 1;
    for (int i = 1; i <= k; i++) {
        if (!in[i]) cout << 0;
        else cout << 2*(r[i]-l[i]+1);
        cout << " \n"[i == k];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
