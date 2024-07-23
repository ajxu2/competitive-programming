// created: 07-16-2024 Tue 09:45 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; string s; cin >> n >> s;
    int chunks = 0;
    for (int i = 0; i < ssize(s) - 1; i++) if (s[i] == '0' && s[i+1] == '1') chunks++;
    if (s.back() == '0') chunks++;
    int ones = 0;
    for (char i : s) if (i == '1') ones++;
    cout << (ones > chunks ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
