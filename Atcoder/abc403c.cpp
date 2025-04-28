// created: 04-27-2025 Sun 08:05 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    V<set<int>> a(n);
    V<bool> admin(n, false);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y; x--, y--;
            a[x].insert(y);
        } else if (t == 2) {
            int x; cin >> x; x--;
            admin[x] = true;
        } else {
            int x, y; cin >> x >> y; x--, y--;
            if (admin[x] || a[x].contains(y))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}
