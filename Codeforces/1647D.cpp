// created: 03-11-2022 Fri 09:32 AM

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d; cin >> n >> d;
    vector<int> fac, bfac;
    for (int i = 1; i*i <= n; i++) {
        if (n % i != 0) continue;
        int j = n/i;
        fac.push_back(i); if (i != j) fac.push_back(j);
        if (i % d == 0 && (i/d) % d != 0) bfac.push_back(i);
        if (i != j && j % d == 0 && (j/d) % d != 0) bfac.push_back(j);
    }
    sort(fac.begin(), fac.end());
    sort(bfac.begin(), bfac.end());
    // now it's just like Coin Combinations II on CSES, except with multiplication
    map<int, int> dp;
    for (int i : fac) dp[i] = 0;
    dp[1] = 1;
    for (int i : bfac) {
        for (int j : fac) {
            if (j % i == 0) dp[j] += dp[j/i];
        }
    }
    cout << (dp[n] >= 2 ? "YES" : "NO") << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
