// created: 05-27-2022 Fri 01:19 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s; cin >> s;
    map<char, int> m;
    int n = 0;
    for (char i : s) {
        if (m.count(i)) continue;
        m[i] = n;
        n++;
    }
    vector<vector<int>> freq(n, vector<int>(n, 0));
    for (int i = 0; i < s.length()-1; i++) freq[m[s[i]]][m[s[i+1]]]++;
    vector<int> dp(1<<n, 1e9);
    dp[0] = 1;
    for (int i = 1; i < 1<<n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i&1<<j) == 0) continue;
            int toAdd = 0;
            for (int k = 0; k < n; k++) {
                if ((i&1<<k) == 0) continue;
                toAdd += freq[j][k];
            }
            dp[i] = min(dp[i], dp[i^1<<j]+toAdd);
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    return 0;
}
