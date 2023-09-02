// created: 09-02-2023 Sat 11:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<int> a(n);
    for (int& i : a) cin >> i;
    sort(begin(a), end(a));
    while (q--) {
        int k; cin >> k;
        V<int> b = a;
        if (k <= n) {
            for (int i = 0; i < k; i++) b[i] += k - i;
            cout << *min_element(begin(b), end(b)) << " ";
        } else {
            for (int i = 0; i < n - (k - n) % 2; i++) b[i] += k - i;
            int mn = *min_element(begin(b), end(b));
            int sub = (k - n + (k - n) % 2) / 2;
            ll buf = accumulate(begin(b), end(b), 0LL) - (ll)n * mn;
            if (sub <= buf) cout << mn << " ";
            else {
                int aft = sub - buf;
                cout << mn - (aft + n - 1) / n << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
