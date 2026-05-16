// created: 05-16-2026 Sat 09:24 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; int n; cin >> s >> n;
    cout << s.substr(n, ssize(s) - 2 * n) << '\n';
    return 0;
}
