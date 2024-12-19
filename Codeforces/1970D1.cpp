// created: 12-17-2024 Tue 11:48 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int cnt_distinct_substrings(string s) {
    set<string> se;
    for (int i = 0; i < ssize(s); i++) {
        for (int j = 1; j <= ssize(s) - i; j++) {
            se.insert(s.substr(i, j));
        }
    }
    return ssize(se);
}

int main() {
    // i just wrote a script to try random strings and it found this
    V<string> a = {"OX", "XXX", "XXOX"};
    map<int, array<int, 2>> lookup;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            lookup[cnt_distinct_substrings(a[i] + a[j])] = {i + 1, j + 1};
        }
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) cout << a[i] << endl;
    int q; cin >> q;
    while (q--) {
        int p; cin >> p;
        array<int, 2> ans = lookup[p];
        cout << ans[0] << ' ' << ans[1] << endl;
    }
    return 0;
}
