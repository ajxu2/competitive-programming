// created: 12-29-2025 Mon 08:39 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int a, b; cin >> a >> b;
    int c = 0, d = 0;
    int i = 0;
    for (;;) {
        if (i % 2 == 0)
            c += 1 << i;
        else
            d += 1 << i;
        if (!((c <= a && d <= b) || (d <= a && c <= b)))
            break;
        i++;
    }
    cout << i << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
