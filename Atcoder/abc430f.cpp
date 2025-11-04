// created: 11-01-2025 Sat 08:51 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> cur_chain;
    cur_chain.push_back(0);
    V<int> rnk(n, 0);
    V<V<int>> chains;
    for (int i = 0; i < n - 1; i++) {
        cur_chain.push_back(i + 1);
        if (i == n - 2 || s[i] != s[i + 1]) {
            if (s[i] == 'L')
                reverse(begin(cur_chain), end(cur_chain));
            chains.push_back(cur_chain);
            cur_chain.clear();
            cur_chain.push_back(i + 1);
        }
    }
    V<int> cnt_above(n, 0), cnt_below(n, 0);
    for (V<int> chain : chains) {
        for (int i = 0; i < ssize(chain); i++) {
            cnt_above[chain[i]] += ssize(chain) - i - 1;
            cnt_below[chain[i]] += i;
        }
    }
    V<int> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        p[cnt_below[i]]++;
        p[n - cnt_above[i]]--;
    }
    for (int i = 1; i <= n; i++)
        p[i] += p[i - 1];
    for (int i = 0; i < n; i++)
        cout << p[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
