// created: 06-23-2024 Sun 10:06 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1e9;
    for (int i = 0; i < n-1; i++) {
        V<int> nums;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                nums.push_back(stoi(s.substr(j, 2)));
                j++;
            } else nums.push_back(s[j] - '0');
        }
        int cur = nums[0];
        for (int i = 1; i < n-1; i++) {
            if (nums[i] <= 1 || cur <= 1) cur *= nums[i];
            else cur += nums[i];
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
