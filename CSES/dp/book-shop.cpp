#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void ckmin(int& a, int b) { a = min(a, b); }
void ckmax(int& a, int b) { a = max(a, b); }

int main() {
    int n, x; cin >> n >> x;
    V<int> h(n), s(n);
    for (int& i : h) cin >> i;
    for (int& i : s) cin >> i;
    V<int> dp1(x+1, 0), dp2(x+1, 0); // dp[i] = number of pages if budget i
    for (int i = 1; i <= n; i++) {
        dp2 = dp1;
        // calculate the answers if we use the i-th book
        for (int j = 1; j <= x; j++) {
            if (j - h[i-1] >= 0) ckmax(dp2[j], dp1[j-h[i-1]] + s[i-1]);
        }
        swap(dp1, dp2);
    }
    cout << dp1[x] << "\n";
    return 0;
}
