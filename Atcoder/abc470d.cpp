// created: 08-08-2026 Sat 08:52 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> p(n);
    for (int& i : p)
        cin >> i, i--;
    V<int> ip(n);
    for (int i = 0; i < n; i++)
        ip[p[i]] = i;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; x--, y--;
            swap(p[x], p[y]);
            swap(ip[p[x]], ip[p[y]]);
        } else {
            swap(p, ip);
        }
    }
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " \n"[i == n - 1];
    return 0;
}
