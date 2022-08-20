// created: 08-05-2022 Fri 10:06 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> p(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) p[i] ^= p[i-1];
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        cout << (p[y] ^ p[x-1]) << "\n";
    }
    return 0;
}
