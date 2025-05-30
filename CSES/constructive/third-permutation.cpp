// created: 05-30-2025 Fri 01:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    V<int> c(n);
    iota(begin(c), end(c), 1);
    for (int i = 0; i < 100; i++) {
        shuffle(begin(c), end(c), rng);
        bool ok = true;
        for (int j = 0; j < n; j++)
            ok &= (a[j] != c[j] && b[j] != c[j]);
        if (ok) {
            for (int j = 0; j < n; j++)
                cout << c[j] << " \n"[j == n-1];
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
