// created: 11-24-2024 Sun 01:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;
const int INF = 1'000'000'007;
void mod_add(int& a, int b) { a = (a + b) % MOD; }
void mod_sub(int& a, int b) { a = (a + MOD - b) % MOD; }

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    a.insert(begin(a), INF);
    a.push_back(INF);
    V<int> dp(n+2, 0), pdp(n+2, 0);
    dp[0] = 1;
    pdp[0] = 1;
    stack<int> stk; stk.push(0);
    int sum = 1;
    for (int i = 1; i < n+2; i++) {
        while (!empty(stk) && a[i] < a[stk.top()]) {
            mod_sub(sum, dp[stk.top()]);
            stk.pop();
        }
        mod_add(dp[i], sum);
        mod_add(dp[i], pdp[i-1]);
        if (!empty(stk)) mod_sub(dp[i], pdp[stk.top()]);
        stk.push(i);
        mod_add(sum, dp[i]);
        pdp[i] = pdp[i-1];
        mod_add(pdp[i], dp[i]);
    }
    cout << dp[n+1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
