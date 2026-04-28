// created: 04-25-2026 Sat 08:55 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    cout << (a != b && b == c ? "Yes" : "No") << '\n';
    return 0;
}
