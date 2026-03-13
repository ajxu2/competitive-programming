// created: 03-02-2026 Mon 08:28 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    cout << (n >= 2 * m - 1 ? "Yes" : "No") << '\n';
    return 0;
}
