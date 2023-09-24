// created: 09-24-2023 Sun 09:42 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n; cin >> n;
    V<int> a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    ll mna = *min_element(begin(a), end(a)), mnb = *min_element(begin(b), end(b)), sma = accumulate(begin(a), end(a), 0LL), smb = accumulate(begin(b), end(b), 0LL);
    cout << min(mna * n + smb, mnb * n + sma) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
