// created: 02-26-2023 Sun 01:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<ll> a(n);
    for (ll& i : a) cin >> i;
    V<ll> p(n+1, 0);
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i-1];
    V<array<ll, 3>> sums; // (sum, left, right)
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sums.push_back({p[j+1] - p[i], i, j});
        }
    }
    sort(sums.begin(), sums.end());
    for (int i = 0; i < n; i++) {
        // solve for this i
        ll ans = 1e18;
        for (int j = 0; j < sums.size() - 1; j++) {
            if ((sums[j][1] <= i && i <= sums[j][2]) ^ (sums[j+1][1] <= i && i <= sums[j+1][2])) {
                ans = min(ans, abs(sums[j+1][0] - sums[j][0]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
