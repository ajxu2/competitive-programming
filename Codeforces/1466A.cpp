#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& i : nums) {
        cin >> i;
    }
    set<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans.insert(nums[i] - nums[j]);
        }
    }
    cout << (int)ans.size() << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
