// created: 04-25-2026 Sat 08:42 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> nxt(2 * n, -1), prv(2 * n, -1);
    for (int i = 0; i < n; i++) {
        nxt[i + n] = i;
        prv[i] = i + n;
    }
    while (q--) {
        int c, p; cin >> c >> p; c--, p--;
        nxt[prv[c]] = -1;
        prv[c] = p;
        nxt[p] = c;
    }
    for (int i = 0; i < n; i++) {
        int sz = 0;
        for (int j = i + n; j != -1; j = nxt[j])
            sz++;
        sz--;
        cout << sz << " \n"[i == n - 1];
    }
    return 0;
}
