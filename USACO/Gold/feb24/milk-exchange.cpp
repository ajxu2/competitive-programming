// created: 06-02-2024 Sun 02:15 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    V<ll> ans(n + 1, 0);
    V<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.back()] >= a[i])
            stk.pop_back();
        stk.push_back(i);
    }
    for (int i = 0; i < sz(stk) - 1; i++) {
        ans[n - stk[i]] += a[stk[i]] - a[stk[i + 1]];
    }
    // something about monotonic stack and prefix sums bro idek
    for (int i = n; i < 2 * n; i++) {
        while (!stk.empty() && a[stk.back()] >= a[i]) {
            int top = stk.back();
            stk.pop_back();
            if (!stk.empty()) {
                int top2 = stk.back();
                ans[i - top2] -= a[top2] - a[top];
            }
        }
        stk.push_back(i);
        if (sz(stk) > 1) {
            int top2 = end(stk)[-2];
            ans[i - top2] += a[top2] - a[i];
        }
    }
    for (int i = 0; i < sz(stk) - 1; i++) {
        ans[2 * n - stk[i]] -= a[stk[i]] - a[stk[i + 1]];
    }
    for (int i = 1; i < n + 1; i++)
        ans[i] += ans[i - 1];
    ans[0] = accumulate(begin(a), begin(a) + n, 0LL);
    for (int i = 1; i < n + 1; i++)
        ans[i] += ans[i - 1];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}
