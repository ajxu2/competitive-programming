// created: 11-15-2025 Sat 05:01 PM

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
    map<int, int> mp;
    ll ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        int lst = mp.contains(a[i]) ? mp[a[i]] : -1;
        cur += i - lst;
        ans += cur;
        mp[a[i]] = i;
    }
    cout << ans << '\n';
    return 0;
}
