// created: 11-08-2025 Sat 07:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, n; cin >> x >> n;
    V<int> w(n);
    for (int& i : w)
        cin >> i;
    V<bool> on(n, false);
    int q; cin >> q;
    while (q--) {
        int p; cin >> p; p--;
        if (on[p])
            x -= w[p];
        else
            x += w[p];
        on[p].flip();
        cout << x << '\n';
    }
    return 0;
}
