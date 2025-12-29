// created: 12-29-2025 Mon 08:42 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n), c(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    for (int& i : c)
        cin >> i;
    auto calc_tuah = [n](const V<int>& a, const V<int>& b) {
        int res = 0;
        for (int shift = 0; shift < n; shift++) {
            bool good = true;
            for (int i = 0; i < n; i++) {
                if (b[(i + shift) % n] <= a[i])
                    good = false;
            }
            if (good)
                res++;
        }
        return res;
    };
    cout << (ll)n * calc_tuah(a, b) * calc_tuah(b, c) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
