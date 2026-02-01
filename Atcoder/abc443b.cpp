// created: 01-31-2026 Sat 12:05 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = midpoint(l, r);
        ll beans = (ll)(mid + 1) * (n + n + mid) / 2;
        if (beans >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}
