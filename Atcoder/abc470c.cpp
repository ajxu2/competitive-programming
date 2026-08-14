// created: 08-08-2026 Sat 08:56 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n, 0);
    V<int> nonzero;
    int ans = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            ans ^= a[x];
            if (a[x] == 0)
                nonzero.push_back(x);
            a[x]++;
            ans ^= a[x];
        } else {
            V<int> new_nonzero;
            for (int i : nonzero) {
                ans ^= a[i];
                a[i]--;
                ans ^= a[i];
                if (a[i] > 0)
                    new_nonzero.push_back(i);
            }
            nonzero = new_nonzero;
        }
        cout << ans << '\n';
    }
    return 0;
}
