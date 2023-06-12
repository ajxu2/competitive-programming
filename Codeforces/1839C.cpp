// created: 06-03-2023 Sat 10:12 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    if (a.back() != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    V<int> ans;
    while (a.size() > 1) {
        int cnt = n - a.size();
        if ((a[a.size()-2] + cnt) % 2 == 0) {
            ans.push_back(a.size() - 2);
            a.erase(a.end() - 2);
        } else {
            ans.push_back(a.size() - 1);
            a.erase(a.end() - 1);
        }
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
