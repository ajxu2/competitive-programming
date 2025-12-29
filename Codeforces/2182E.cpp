// created: 12-29-2025 Mon 10:12 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, m; ll k; cin >> n >> m >> k;
    V<int> a(m);
    for (int& i : a)
        cin >> i;
    sort(begin(a), end(a), greater<int>());
    V<int> x(n), z(n);
    for (int i = 0; i < n; i++) {
        int one, two, three; cin >> one >> two >> three;
        x[i] = one;
        k -= two;
        z[i] = three - two;
    }
    // find the number of boxes we can use
    V<array<int, 2>> p(n);
    for (int i = 0; i < n; i++)
        p[i] = {x[i], z[i]};
    sort(begin(p), end(p), greater<array<int, 2>>());
    int boxes = 0, ptr = 0;
    while (boxes < m && ptr < n) {
        while (ptr < n && p[ptr][0] > a[boxes])
            ptr++;
        if (ptr < n)
            boxes++, ptr++;
    }
    // use this many boxes
    sort(begin(p), end(p));
    ptr = 0;
    priority_queue<int> costs;
    for (int i = boxes - 1; i >= 0; i--) {
        int box = a[i];
        while (ptr < n && p[ptr][0] <= box)
            costs.push(p[ptr++][1]);
        costs.pop();
    }
    V<int> costs2;
    while (!costs.empty()) {
        costs2.push_back(costs.top());
        costs.pop();
    }
    for (int i = ptr; i < n; i++)
        costs2.push_back(p[i][1]);
    sort(begin(costs2), end(costs2));
    int ans = 0;
    while (ans < ssize(costs2) && k - costs2[ans] >= 0)
        k -= costs2[ans++];
    ans += boxes;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
