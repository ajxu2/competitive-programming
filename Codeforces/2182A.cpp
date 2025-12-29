// created: 12-29-2025 Mon 08:32 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s.find("2025") == string::npos)
        cout << "0\n";
    else if (s.find("2026") != string::npos)
        cout << "0\n";
    else
        cout << "1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
