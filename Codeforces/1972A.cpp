// created: 05-16-2024 Thu 07:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        V<int> a(n), b(n);
        for (int& i : a) cin >> i;
        for (int& i : b) cin >> i;
        int ptr = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (ptr < n && b[ptr] < a[i]) ptr++;
            ans = max(ans, ptr - i);
        }
        cout << ans << '\n';
    }
    return 0;
}
