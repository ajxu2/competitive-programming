// created: 03-12-2023 Sun 09:51 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    ll n, x, p; cin >> n >> x >> p;
    for (ll i = 1; i <= min(5*n, p); i++) {
        if ((x + i*(i+1)/2) % n == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
