// created: 12-20-2024 Fri 08:42 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> caps(n, n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            for (int j = 0; j <= i; j++) {
                caps[j] = min(caps[j], i+1);
            }
        } else if (s[i] == 's') {
            for (int j = i; j < n; j++) {
                caps[j] = min(caps[j], n-i);
            }
        }
    }
    sort(begin(caps), end(caps));
    for (int i = 0; i < n; i++) {
        if (caps[i] < i+1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
