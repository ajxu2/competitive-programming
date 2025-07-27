// created: 07-23-2025 Wed 11:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    // just a bunch of absval functions
    V<int> x(n), t(n);
    for (int& i : x)
        cin >> i;
    for (int& i : t)
        cin >> i;
    // rotate 45 deg clockwise: (x, y) -> (x+y, -x+y)
    for (int i = 0; i < n; i++) {
        int newx = x[i] + t[i];
        int newt = -x[i] + t[i];
        x[i] = newx;
        t[i] = newt;
    }
    int ansx = *max_element(begin(x), end(x));
    int anst = *max_element(begin(t), end(t));
    ansx -= anst;
    cout << fixed << ansx / 2. << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
