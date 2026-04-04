// created: 04-04-2026 Sat 09:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    V<array<int, 2>> a = {{1, 7}, {3, 3}, {5, 5}, {7, 7}, {9, 9}};
    int m, d; cin >> m >> d;
    bool good = false;
    for (auto [u, v] : a)
        good |= (m == u && d == v);
    cout << (good ? "Yes" : "No") << '\n';
    return 0;
}
