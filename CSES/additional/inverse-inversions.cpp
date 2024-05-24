// created: 05-22-2024 Wed 04:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    ll cur = 0; int curidx = n;
    while (curidx > 0 && cur + curidx - 1 < k) {
        cur += curidx - 1; curidx--;
    }
    V<int> ans(n, -1); for (int i = n; i > curidx; i--) ans[n-i] = i;
    ans[n-1-(k-cur)] = curidx;
    curidx = 1;
    for (int i = 0; i < n; i++) if (ans[i] == -1) ans[i] = curidx++;
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
    return 0;
}
