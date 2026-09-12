// created: 08-22-2026 Sat 08:23 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int ans = 1'000'000'007;
    for (int i = 0; i < n - 1; i++) {
        int l1 = 0, l2 = 0;
        for (int j = 0; j < n; j++)
            (j <= i ? l1 : l2) += a[j];
        ans = min(ans, abs(l1 - l2));
    }
    cout << ans << '\n';
    return 0;
}
