// created: 01-17-2026 Sat 07:02 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    array<bool, 26> s_used, t_used;
    s_used.fill(false);
    for (char i : s)
        s_used[i - 'a'] = true;
    t_used.fill(false);
    for (char i : t)
        t_used[i - 'a'] = true;
    int q; cin >> q;
    while (q--) {
        string w; cin >> w;
        bool one = true, two = true;
        for (char i : w) {
            one &= s_used[i - 'a'];
            two &= t_used[i - 'a'];
        }
        if (one && two)
            cout << "Unknown";
        else if (one)
            cout << "Takahashi";
        else
            cout << "Aoki";
        cout << '\n';
    }
    return 0;
}
