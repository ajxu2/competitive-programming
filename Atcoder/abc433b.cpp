// created: 11-22-2025 Sat 07:02 AM

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
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
        while (stk.top() != -1 && a[stk.top()] <= a[i])
            stk.pop();
        int ans = stk.top();
        if (ans != -1)
            ans++;
        cout << ans << '\n';
        stk.push(i);
    }
    return 0;
}
