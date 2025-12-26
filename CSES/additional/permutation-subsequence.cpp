// created: 12-25-2025 Thu 09:10 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int len = min(n, m);
    V<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        if (x < len)
            a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x; x--;
        if (x < len)
            b.push_back(x);
    }
    V<int> inv(len);
    for (int i = 0; i < len; i++)
        inv[b[i]] = i;
    for (int i = 0; i < len; i++)
        a[i] = inv[a[i]];
    // now LIS
    V<int> dp, par(len);
    for (int i : a) {
        auto it = lower_bound(begin(dp), end(dp), i);
        par[i] = it == begin(dp) ? -1 : *prev(it);
        if (it == end(dp))
            dp.push_back(i);
        else
            *it = i;
    }
    V<int> lis;
    int cur = dp.back();
    while (cur != -1) {
        lis.push_back(cur);
        cur = par[cur];
    }
    reverse(begin(lis), end(lis));
    cout << ssize(lis) << '\n';
    for (int i : lis)
        cout << b[i] + 1 << ' ';
    cout << '\n';
    return 0;
}
