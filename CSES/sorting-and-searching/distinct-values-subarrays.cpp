// created: 05-13-2025 Tue 03:06 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    ll ans = 0;
    set<int> se;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        while (ptr < n && !se.contains(a[ptr]))
            se.insert(a[ptr++]);
        ans += ptr - i;
        se.erase(a[i]);
    }
    cout << ans << '\n';
    return 0;
}
