// created: 01-08-2023 Sun 08:31 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
    if (a[0] == a[1]) swap(a[0], a[n-1]);
    if (a[0] == a[1]) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
