// created: 09-19-2026 Sat 11:48 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    bool matches = true;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i] && s[i] != '*' && t[i] != '*')
            matches = false;
    cout << (matches ? "Yes" : "No") << '\n';
    return 0;
}
