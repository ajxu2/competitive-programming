// created: 03-02-2026 Mon 08:23 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    string s1, t1;
    V<int> runs_s, runs_t;
    int cur_s = 0, cur_t = 0;
    for (char i : s) {
        if (i != 'A') {
            s1.push_back(i);
            runs_s.push_back(cur_s);
            cur_s = 0;
        } else {
            cur_s++;
        }
    }
    runs_s.push_back(cur_s);
    for (char i : t) {
        if (i != 'A') {
            t1.push_back(i);
            runs_t.push_back(cur_t);
            cur_t = 0;
        } else {
            cur_t++;
        }
    }
    runs_t.push_back(cur_t);
    if (s1 != t1) {
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < ssize(runs_s); i++)
        ans += abs(runs_s[i] - runs_t[i]);
    cout << ans << '\n';
    return 0;
}
