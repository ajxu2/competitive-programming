#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<int> vals;

int dfs(int node, int parent) {
    vals[node] = nums[node] + vals[parent];
    if (nums[node] + node > n) {
        return vals[node];
    } else if (vals[nums[node] + node] == 0) {
        return dfs(nums[node] + node, node);
    }
    return -1;
}

void solve() {
    cin >> n;
    nums.clear();
    vals.clear();
    nums.push_back(0);
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    for (int i = 0; i <= n; i++) {
        vals.push_back(0);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vals[i] == 0) {
            ans = max(ans, dfs(i, 0));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}

