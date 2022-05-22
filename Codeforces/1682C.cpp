// created: 05-22-2022 Sun 10:46 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    map<int, int> freq;
    bool hasOne = false;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (!freq.count(a)) freq[a] = 1;
        else freq[a]++;
    }
    vector<int> a, b;
    for (pair<int, int> i : freq) {
        if (i.second == 1) {
            hasOne = true;
            if (a.size() < b.size()) a.push_back(i.first);
            else b.push_back(i.first);
        } else {
            a.push_back(i.first);
            b.push_back(i.first);
        }
    }
    int ans = min(a.size(), b.size());
    if (a.size() != b.size() && hasOne) ans++;
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
