// created: 05-13-2025 Tue 04:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
using State = pair<int, char>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n), b(m);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    V<V<State>> dp(n+1, V<State>(m+1, {0, '-'}));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1])
                dp[i][j] = State{dp[i-1][j-1].first + 1, '3'};
            else
                dp[i][j] = max(State{dp[i-1][j].first, '1'}, State{dp[i][j-1].first, '2'});
        }
    }
    int ptr1 = n, ptr2 = m;
    V<int> ans;
    while (ptr1 > 0 && ptr2 > 0) {
        switch (dp[ptr1][ptr2].second) {
            case '1': {
                ptr1--;
                break;
            }
            case '2': {
                ptr2--;
                break;
            }
            case '3': {
                ans.push_back(a[ptr1-1]);
                ptr1--;
                ptr2--;
                break;
            }
        }
    }
    reverse(begin(ans), end(ans));
    cout << dp[n][m].first << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}
