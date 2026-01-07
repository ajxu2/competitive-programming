// created: 01-07-2026 Wed 09:20 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    sort(begin(a), end(a));
    int mex;
    if (a[0] > 0) {
        mex = 0;
    } else {
        mex = a[n - 1] + 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 1) {
                mex = a[i - 1] + 1;
                break;
            }
        }
    }
    cout << min(k - 1, mex) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
