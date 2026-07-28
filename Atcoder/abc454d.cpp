// created: 04-18-2026 Sat 08:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

string something(string s) {
    // remove all ((...((xx))...))
    int n = ssize(s);
    // find all xx
    V<int> xx;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == 'x' && s[i + 1] == 'x')
            xx.push_back(i);
    V<array<int, 2>> intervals;
    for (int i : xx) {
        int len = 0;
        while (i - len - 1 >= 0 && s[i - len - 1] == '(' && i + len + 2 < n && s[i + len + 2] == ')')
            len++;
        if (len > 0)
            intervals.push_back({i - len, i + len + 2});
    }
    V<int> skip(n, -1);
    for (auto [l, r] : intervals)
        skip[l] = r;
    string t;
    int i = 0;
    while (i < n) {
        if (skip[i] == -1) {
            t.push_back(s[i]);
            i++;
        } else {
            t.push_back('x');
            t.push_back('x');
            i = skip[i];
        }
    }
    return t;
}

void solve() {
    string s, t; cin >> s >> t;
    cout << (something(s) == something(t) ? "Yes" : "No") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
