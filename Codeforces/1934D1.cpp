// created: 12-10-2024 Tue 01:46 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;

void solve() {
    // just think about it.
    ull n, m; cin >> n >> m;
    if (countl_zero(n) == countl_zero(m)) {
        cout << "1\n" << n << ' ' << m << '\n';
    } else {
        // get second most significant set bit
        ull tmp = n - (1LL << (63 - countl_zero(n)));
        if (countl_zero(tmp) <= countl_zero(m)) {
            // set all zeros after msb to one
            tmp = (bit_floor(tmp) << 1) - 1;
            if (tmp == m) {
                cout << "1\n" << n << ' ' << m << '\n';
            } else {
                cout << "2\n" << n << ' ' << tmp << ' ' << m << '\n';
            }
        } else {
            cout << "-1\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
