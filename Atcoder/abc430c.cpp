// created: 11-01-2025 Sat 08:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int cnt_a = 0, cnt_b = 0;
    int r_a = -1, r_b = -1;
    ll ans = 0;
    for (int l = 0; l < n; l++) { // [l, r]
        while (r_a < n && cnt_a < a) {
            r_a++;
            if (r_a == n)
                break;
            if (s[r_a] == 'a')
                cnt_a++;
        }
        while (r_b < n && cnt_b < b) {
            r_b++;
            if (r_b == n)
                break;
            if (s[r_b] == 'b')
                cnt_b++;
        }
        ans += max(0, r_b - r_a);
        if (s[l] == 'a')
            cnt_a--;
        else
            cnt_b--;
    }
    cout << ans << '\n';
    return 0;
}
