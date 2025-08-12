// created: 08-11-2025 Mon 10:38 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    priority_queue<array<int, 2>> pq;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
            pq.push({a[i], i});
    }
    V<array<int, 2>> ans;
    while (!pq.empty()) {
        auto [deg, i] = pq.top();
        pq.pop();
        V<array<int, 2>> stuff;
        for (int i = 0; i < deg; i++) {
            if (pq.empty()) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            stuff.push_back(pq.top());
            pq.pop();
        }
        for (auto [deg1, j] : stuff) {
            ans.push_back({i, j});
            deg1--;
            if (deg1 > 0)
                pq.push({deg1, j});
        }
    }
    cout << ssize(ans) << '\n';
    for (auto [u, v] : ans)
        cout << u + 1 << ' ' << v + 1 << '\n';
    return 0;
}
