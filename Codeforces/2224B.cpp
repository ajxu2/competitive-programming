// created: 05-06-2026 Wed 12:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
         cin >> i;
    auto calc = [&](const V<int>& a) -> ll {
        int mex = 0, mx = 0;
        ll res = 0;
        V<bool> seen(n, false);
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            if (a[i] < n) {
                seen[a[i]] = true;
                while (seen[mex])
                    mex++;
            }
            res += mex + mx;
        }
        return res;
    };
    auto get_order = [&](const V<int>& a) -> V<int> {
        // get ordering that maximizes sum of prefix mexes
        map<int, int> f;
        for (int i : a)
            f[i]++;
        V<int> res;
        for (auto& [i, j] : f) {
            res.push_back(i);
            j--;
        }
        for (auto [i, j] : f) {
            for (int k = 0; k < j; k++)
                res.push_back(i);
        }
        return res;
    };
    auto it = max_element(begin(a), end(a));
    int mx = *it;
    a.erase(it);
    V<int> b = get_order(a);
    b.insert(begin(b), mx);
    cout << calc(b) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
