// created: 02-20-2023 Mon 01:31 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void ckmin(int& a, int b) { a = min(a, b); }
void ckmax(int& a, int b) { a = max(a, b); }

int main() {
    int n; cin >> n;
    V<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        // try subtracting a digit from this number
        for (int j = 1; j <= i; j *= 10) {
            ckmin(dp[i], dp[i-i/j%10]+1);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
