// created: 06-08-2024 Sat 10:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, m; cin >> n >> m;
    array<int, 7> freq; freq.fill(0);
    string s; cin >> s;
    for (char i : s) freq[i - 'A']++;
    int ans = 0;
    for (int i : freq) ans += max(m - i, 0);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
