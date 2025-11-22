// created: 11-22-2025 Sat 07:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    V<int> splits;
    splits.push_back(-1);
    for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1])
            splits.push_back(i);
    splits.push_back(n - 1);
    ll ans = 0;
    for (int i = 1; i < ssize(splits) - 1; i++) {
        int idx = splits[i];
        if (s[idx] + 1 == s[idx + 1])
            ans += min(splits[i] - splits[i - 1], splits[i + 1] - splits[i]);
    }
    cout << ans << '\n';
    return 0;
}
