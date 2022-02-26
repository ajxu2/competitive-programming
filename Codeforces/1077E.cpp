// created: 02-20-2022 Sun 05:13 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; 
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        freq[tmp]++;
    }
    // we don't care about the actual topic, only the frequency
    vector<int> freq2;
    for (pair<int, int> i : freq) freq2.push_back(i.second);
    sort(freq2.begin(), freq2.end(), greater<int>());
    // maximum starting number given i+1 contests
    vector<int> dp(freq2.size());
    dp[0] = freq2[0];
    for (int i = 1; i < freq2.size(); i++) {
        dp[i] = min(dp[i-1]/2, freq2[i]);
    }
    int ans = 0;
    for (int i = 0; i < freq2.size(); i++) {
        ans = max(ans, dp[i]*((1<<(i+1))-1));
    }
    cout << ans << "\n";
    return 0;
}
