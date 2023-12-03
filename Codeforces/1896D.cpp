// created: 11-30-2023 Thu 06:02 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

void solve() {
    int n, q; cin >> n >> q;
    set<int> one;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; sum += x;
        if (x == 1) one.insert(i);
    }
    while (q--) {
        short op; cin >> op;
        if (op == 1) {
            int s; cin >> s;
            if (s > sum) {
                cout << "NO\n";
                continue;
            }
            if (empty(one)) {
                if (s % 2 == 0) cout << "YES\n";
                else cout << "NO\n";
                continue;
            }
            int tmp = 2 * (*rbegin(one) + 1) - ssize(one);
            if (tmp >= s || (s - tmp) % 2 == 0) {
                cout << "YES\n";
                continue;
            }
            int tmp2 = *rbegin(one) + (s - tmp + 1) / 2;
            //cout << "tmp = " << tmp << "\n";
            //cout << "tmp2 = " << tmp2 << "\n";
            if (one.upper_bound(n - 1 - tmp2) == begin(one)) cout << "NO\n";
            else cout << "YES\n";
        } else {
            int i; short v; cin >> i >> v; i--;
            if (v == 1 && !one.contains(i)) {
                one.insert(i); sum--;
            } else if (v == 2 && one.contains(i)) {
                one.erase(i); sum++;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
