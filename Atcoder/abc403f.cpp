// created: 04-27-2025 Sun 08:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

string str_min(string s, string t) {
    if (s == "")
        return t;
    if (t == "")
        return s;
    if (ssize(s) <= ssize(t))
        return s;
    return t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<string, 2>> ans(n+1); // no outer +, with outer +
    for (int i = 1; i <= n; i++) {
        string str_i = to_string(i);
        // nothing
        if (all_of(begin(str_i), end(str_i), [](char c) { return c == '1'; })) {
            ans[i][0] = str_i;
            ans[i][1] = str_i;
        }
        // multiplication
        for (int j = 2; j * j <= i; j++) {
            if (i % j != 0)
                continue;
            int k = i / j;
            string str_j = str_min(ans[j][0], "(" + ans[j][1] + ")");
            string str_k = str_min(ans[k][0], "(" + ans[k][1] + ")");
            string now = str_j + "*" + str_k;
            ans[i][0] = str_min(ans[i][0], now);
        }
        ans[i][1] = str_min(ans[i][1], ans[i][0]);
        // addition
        for (int j = 1; j <= i / 2; j++) {
            string now = ans[j][1] + "+" + ans[i - j][1];
            ans[i][1] = str_min(ans[i][1], now);
        }
    }
    cout << ans[n][1] << '\n';
    /*
    for (int i = 1; i <= n; i++)
        cout << i << ": " << ans[i][1] << '\n';
    */
    return 0;
}
