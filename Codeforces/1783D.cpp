#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MOD = 998'244'353;

void ad(int& a, int b) {
    a += b;
    if (a > MOD) a -= MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    V<V<int>> dp(n-1, V<int>(200000, 0)); // dp[i][j] = number of ways to make a[i+1]=j after i ops
    dp[0][a[1]+90000] = 1;
    for (int i = 0; i < n-2; i++) {
        for (int j = -90000; j <= 90000; j++) {
            ad(dp[i+1][a[i+2]+j+90000], dp[i][j+90000]);
            if (j != 0) ad(dp[i+1][a[i+2]-j+90000], dp[i][j+90000]);
        }
    }
    int ans = 0;
    for (int j = -90000; j <= 90000; j++) ad(ans, dp[n-2][j+90000]);
    cout << ans << "\n";
    return 0;
}
