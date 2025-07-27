// created: 07-24-2025 Thu 12:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    string s; cin >> s;
    int i = 1;
    while (i < ssize(s) && s[i] == '0')
        i++;
    if (i == ssize(s)) {
        cout << "-1\n";
        return;
    }
    int a = stoi(s.substr(0, i)), b = stoi(s.substr(i));
    if (a < b)
        cout << a << ' ' << b << '\n';
    else
        cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
