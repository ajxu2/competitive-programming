// created: 07-24-2024 Wed 11:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

ll advertisement(V<int>& a) {
    int n = ssize(a);
    V<int> l(n), r(n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        l[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n-1; i >= 0; i--) {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        r[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, (ll)a[i] * (r[i] - l[i] - 1));
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    ll ans = 0; V<int> cur(m, 0);
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for (int j = 0; j < m; j++) {
            if (tmp[j] == '*') cur[j] = 0;
            else cur[j]++;
        }
        ans = max(ans, advertisement(cur));
    }
    cout << ans << '\n';
    return 0;
}
