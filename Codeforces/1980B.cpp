// created: 06-08-2024 Sat 10:04 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, f, k; cin >> n >> f >> k; f--;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int num = a[f];
    sort(begin(a), end(a), greater<int>());
    int fst = -1, lst = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == num) {
            if (fst == -1) fst = i;
            lst = i;
        }
    }
    if (lst < k) cout << "YES\n";
    else if (fst >= k) cout << "NO\n";
    else cout << "MAYBE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
