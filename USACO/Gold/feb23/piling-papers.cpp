// created: 02-26-2023 Sun 04:49 PM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
 
const int MOD = 1'000'000'007;
 
void mod_add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
 
int N; ll A, B;
int a[305];
int dp[305][20][20][3];
 
V<V<int>> solve(ll X) {
    // return the answers for each range if the number can be <= X
    // convert X to a vector
    V<int> A;
    while (X > 0) {
        A.insert(A.begin(), X % 10);
        X /= 10;
    }
    int len = A.size();
    V<V<int>> ans(N, V<int>(N+1, 0));
    for (int i = 0; i < N; i++) {
        // compute ans[i][smth]
        memset(dp, 0, sizeof dp);
        for (int j = i; j <= N; j++) for (int l = 0; l <= len; l++) dp[j][l][l][1] = 1;
        for (int j = i+1; j <= N; j++) {
            for (int l = 0; l < len; l++) {
                for (int r = l+1; r <= len; r++) {
                    // ignored
                    mod_add(dp[j][l][r][0], dp[j-1][l][r][0]);
                    mod_add(dp[j][l][r][1], dp[j-1][l][r][1]);
                    mod_add(dp[j][l][r][2], dp[j-1][l][r][2]);
                    // added to left
                    if (a[j-1] < A[l]) {
                        mod_add(dp[j][l][r][0], dp[j-1][l+1][r][0]);
                        mod_add(dp[j][l][r][0], dp[j-1][l+1][r][1]);
                        mod_add(dp[j][l][r][0], dp[j-1][l+1][r][2]);
                    } else if (a[j-1] == A[l]) {
                        mod_add(dp[j][l][r][0], dp[j-1][l+1][r][0]);
                        mod_add(dp[j][l][r][1], dp[j-1][l+1][r][1]);
                        mod_add(dp[j][l][r][2], dp[j-1][l+1][r][2]);
                    } else if (a[j-1] > A[l]) {
                        mod_add(dp[j][l][r][2], dp[j-1][l+1][r][0]);
                        mod_add(dp[j][l][r][2], dp[j-1][l+1][r][1]);
                        mod_add(dp[j][l][r][2], dp[j-1][l+1][r][2]);
                    }
                    // added to right
                    if (a[j-1] < A[r-1]) {
                        mod_add(dp[j][l][r][0], dp[j-1][l][r-1][0]);
                        mod_add(dp[j][l][r][0], dp[j-1][l][r-1][1]);
                        mod_add(dp[j][l][r][2], dp[j-1][l][r-1][2]);
                    } else if (a[j-1] == A[r-1]) {
                        mod_add(dp[j][l][r][0], dp[j-1][l][r-1][0]);
                        mod_add(dp[j][l][r][1], dp[j-1][l][r-1][1]);
                        mod_add(dp[j][l][r][2], dp[j-1][l][r-1][2]);
                    } else if (a[j-1] > A[r-1]) {
                        mod_add(dp[j][l][r][0], dp[j-1][l][r-1][0]);
                        mod_add(dp[j][l][r][2], dp[j-1][l][r-1][1]);
                        mod_add(dp[j][l][r][2], dp[j-1][l][r-1][2]);
                    }
                }
            }
        }
        for (int j = i+1; j <= N; j++) {
            mod_add(ans[i][j], dp[j][0][len][0]);
            mod_add(ans[i][j], dp[j][0][len][1]);
            for (int r = 1; r < len; r++) {
                mod_add(ans[i][j], dp[j][0][r][0]);
                mod_add(ans[i][j], dp[j][0][r][1]);
                mod_add(ans[i][j], dp[j][0][r][2]);
            }
        }
    }
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) cin >> a[i];
    V<V<int>> ans1 = solve(B), ans2 = solve(A-1);
    int Q; cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r;
        int ans = ans1[l-1][r] - ans2[l-1][r];
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
    return 0;
}
