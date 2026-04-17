// created: 01-22-2026 Thu 01:41 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<bool> dp(k + 1, false);
    for (int i = 1; i <= k; i++)
        for (int j : a)
            if (i >= j && !dp[i - j])
                dp[i] = true;
    cout << (dp[k] ? "First" : "Second") << '\n';
    return 0;
}
