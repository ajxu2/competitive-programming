// created: 08-30-2025 Sat 08:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> s(n);
    for (string& i : s)
        cin >> i;
    int x; string y; cin >> x >> y; x--;
    cout << (s[x] == y ? "Yes" : "No") << '\n';
    return 0;
}
