// created: 01-17-2026 Sat 07:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int p, q; cin >> p >> q;
    int x, y; cin >> x >> y;
    if (p <= x && x < p + 100 && q <= y && y < q + 100)
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';
    return 0;
}
