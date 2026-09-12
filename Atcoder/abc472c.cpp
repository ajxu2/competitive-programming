// created: 08-22-2026 Sat 08:19 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; ll k; cin >> n >> m >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    ll sum = 0;
    V<bool> ate(n, false);
    for (int i = 0; i < n; i++) {
        if (i >= m && ate[i - m])
            sum -= a[i - m];
        if (sum + a[i] <= k) {
            ate[i] = true;
            sum += a[i];
        }
        cout << (ate[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}
