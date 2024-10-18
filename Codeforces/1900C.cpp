// created: 10-17-2024 Thu 10:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    auto calc = [&](auto&& self, int x) -> int {
        if (l[x] == -1 && r[x] == -1) return 0;
        if (l[x] == -1) {
            if (s[x] != 'R') return 1 + self(self, r[x]);
            else return self(self, r[x]);
        } else if (r[x] == -1) {
            if (s[x] != 'L') return 1 + self(self, l[x]);
            else return self(self, l[x]);
        } else {
            if (s[x] == 'L') return min(self(self, l[x]), 1 + self(self, r[x]));
            else if (s[x] == 'R') return min(1 + self(self, l[x]), self(self, r[x]));
            else return 1 + min(self(self, l[x]), self(self, r[x]));
        }
    };
    cout << calc(calc, 0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
