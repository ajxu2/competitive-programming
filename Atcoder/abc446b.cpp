// created: 02-23-2026 Mon 07:27 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<bool> ok(m, true);
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        int chosen = -1;
        for (int j = 0; j < l; j++) {
            int x; cin >> x; x--;
            if (chosen == -1 && ok[x]) {
                chosen = x;
                ok[x] = false;
            }
        }
        cout << chosen + 1 << '\n';
    }
    return 0;
}
