// created: 08-06-2025 Wed 12:40 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // key idea: add 1 to all elements, if two consecutive numbers aren't in
    // the same order, then the starting letters can't be the same
    int n; cin >> n;
    V<int> a(n);
    V<int> inv(n+1);
    inv[n] = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        inv[a[i]] = i;
    }
    string ans(n, 'a');
    int cur = 0;
    for (int i = 1; i < n; i++) {
        if (inv[a[i-1]+1] > inv[a[i]+1])
            cur++;
        if (cur >= 26) {
            cout << "-1\n";
            return 0;
        }
        ans[a[i]] = 'a' + cur;
    }
    cout << ans << '\n';
    return 0;
}
