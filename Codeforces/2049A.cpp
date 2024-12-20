// created: 12-20-2024 Fri 08:34 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    // check if all zeros
    if (all_of(begin(a), end(a), [](int x) { return x == 0; })) {
        cout << "0\n";
    } else {
        // check nonzero elements contiguous
        int cnt_segments = 0;
        if (a[0] != 0) cnt_segments++;
        for (int i = 1; i < n; i++) {
            if (a[i] != 0 && a[i-1] == 0) cnt_segments++;
        }
        if (cnt_segments == 1) cout << "1\n";
        else cout << "2\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
