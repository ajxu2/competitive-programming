// created: 04-09-2023 Sun 09:45 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int x, y; cin >> x >> y;
    cout << "2\n";
    cout << "1" << " " << y-1 << "\n";
    cout << x << " " << y << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
