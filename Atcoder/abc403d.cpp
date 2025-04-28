// created: 04-27-2025 Sun 08:10 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    if (d == 0) {
        cout << n - ssize(mp) << '\n';
        return 0;
    }
    int ans = 0;
    while (!empty(mp)) {
        int cur = begin(mp)->first;
        V<int> freq;
        while (mp.contains(cur)) {
            auto it = mp.find(cur);
            freq.push_back(it->second);
            mp.erase(it);
            cur += d;
        }
        V<array<int, 2>> dp(ssize(freq));
        dp[0] = {0, freq[0]};
        for (int i = 1; i < ssize(freq); i++) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + freq[i];
        }
        ans += min(dp.back()[0], dp.back()[1]);
    }
    cout << ans << '\n';
    return 0;
}
