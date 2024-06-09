// created: 06-09-2024 Sun 09:44 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    string s; cin >> s;
    if (s[0] != '1' || s.back() == '9') {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < sz(s) - 1; i++) if (s[i] == '0') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
