// created: 11-08-2025 Sat 07:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<int> h(n), b(m);
    for (int& i : h)
        cin >> i;
    for (int& i : b)
        cin >> i;
    sort(begin(h), end(h));
    sort(begin(b), end(b));
    int r = 0, ans = 0;
    for (int l = 0; l < n; l++) {
        while (r < m && b[r] < h[l])
            r++;
        if (r < m) {
            ans++;
            r++;
        }
    }
    cout << (ans >= k ? "Yes" : "No") << '\n';
    return 0;
}
