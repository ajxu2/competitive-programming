// created: 07-25-2023 Tue 11:16 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)a.size(); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<string> a(n);
    for (string& i : a) cin >> i;
    V<array<int, 2>> b(n);
    for (int i = 0; i < n; i++) {
        V<int> freq(26, 0);
        for (char j : a[i]) freq[j-'a']++;
        b[i][0] = 0; b[i][1] = 0;
        for (int j = 0; j < 26; j++) {
            if (freq[j] != 0) b[i][0] += (1 << j);
            b[i][1] += (freq[j] & 1) * (1 << j);
        }
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        V<int> c;
        for (int j = 0; j < n; j++) {
            if ((b[j][0] & (1 << i)) == 0) c.push_back(b[j][1]);
        }
        sort(c.begin(), c.end());
        for (int j : c) {
            int other = j ^ ((1 << 26) - 1) ^ (1 << i);
            ans += upper_bound(c.begin(), c.end(), other) - lower_bound(c.begin(), c.end(), other);
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}
