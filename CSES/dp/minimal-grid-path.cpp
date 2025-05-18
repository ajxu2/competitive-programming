// created: 05-14-2025 Wed 05:51 PM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
template<class T> using V = vector<T>;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> grid(n);
    for (string& i : grid)
        cin >> i;
    // just put the characters in the string bro 😂😂😂
    // (which means build the string one char at a time)
    string ans;
    V<V<bool>> is_candidate(n, V<bool>(n, false));
    is_candidate[0][0] = true;
    char nxt = grid[0][0];
    for (int sum = 0; sum <= 2 * n - 2; sum++) {
        ans.push_back(nxt);
        nxt = '^';
        for (int i = 0; i < n; i++) {
            int j = sum - i;
            if (j < 0 || j >= n)
                continue;
            if (!is_candidate[i][j])
                continue;
            if (i < n-1)
                nxt = min(nxt, grid[i+1][j]);
            if (j < n-1)
                nxt = min(nxt, grid[i][j+1]);
        }
        for (int i = 0; i < n; i++) {
            int j = sum - i;
            if (j < 0 || j >= n)
                continue;
            if (!is_candidate[i][j])
                continue;
            if (i < n-1 && grid[i+1][j] == nxt)
                is_candidate[i+1][j] = true;
            if (j < n-1 && grid[i][j+1] == nxt)
                is_candidate[i][j+1] = true;
        }
    }
    cout << ans << '\n';
    return 0;
}
