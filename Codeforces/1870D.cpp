// created: 09-18-2023 Mon 10:47 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> c(n);
    for (int& i : c) cin >> i;
    int k; cin >> k;
    V<int> sfx(n+1, -1); // sfx min el
    int mn = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (c[i] < mn) {
            sfx[i] = i; mn = c[i];
        } else sfx[i] = sfx[i+1];
    }
    V<int> ans(n, 0);
    int ptr = sfx[0];
    ans[ptr] = k / c[ptr];
    k -= c[ptr] * ans[ptr];
    int pre = ptr; ptr = sfx[ptr+1];
    while (ptr != -1) {
        int fake = c[ptr] - c[pre];
        ans[ptr] = min(ans[pre], k / fake); ans[pre] -= ans[ptr];
        k -= fake * ans[ptr];
        pre = ptr, ptr = sfx[ptr+1];
    }
    for (int i = n-2; i >= 0; i--) ans[i] += ans[i+1];
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
