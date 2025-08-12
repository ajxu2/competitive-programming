// created: 07-27-2025 Sun 11:37 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<int> suffix_array(string s) {
    // construct the suffix array of s - the suffixes in sorted order
    s.push_back('$');
    int n = ssize(s);
    V<int> rnk(n);
    for (int i = 0; i < n; i++)
        rnk[i] = (int)s[i];
    V<int> stuff(n);
    iota(begin(stuff), end(stuff), 0);
    for (int i = 1; i < n; i <<= 1) {
        V<array<int, 2>> pairs(n);
        for (int j = 0; j < n; j++) {
            pairs[j] = {rnk[j], rnk[(j + i) % n]};
        }
        sort(begin(stuff), end(stuff), [&pairs](int i, int j) {
            return pairs[i] < pairs[j];
        });
        array<int, 2> lst = {-1, -1};
        int cur = 0;
        for (int j : stuff) {
            if (pairs[j] != lst) {
                lst = pairs[j];
                cur++;
            }
            rnk[j] = cur;
        }
    }
    stuff.erase(begin(stuff));
    return stuff;
}

V<int> lcp_array(string s, V<int> sa) {
    // construct the lcp array - the lcp between each pair of adjacents
    int n = ssize(s);
    s.push_back('$');
    V<int> inv(n);
    for (int i = 0; i < n; i++)
        inv[sa[i]] = i;
    V<int> lcp(n-1, 0);
    int last_lcp = 0;
    for (int i = 0; i < n; i++) {
        int idx = inv[i];
        if (idx == n-1) {
            last_lcp = 0;
            continue;
        }
        if (last_lcp > 0)
            lcp[idx] = last_lcp - 1;
        while (s[i + lcp[idx]] == s[sa[idx+1] + lcp[idx]])
            lcp[idx]++;
        last_lcp = lcp[idx];
    }
    return lcp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    V<int> sa = suffix_array(s);
    V<int> lcp = lcp_array(s, sa);
    auto it = max_element(begin(lcp), end(lcp));
    if (it == end(lcp) || *it == 0)
        cout << "-1\n";
    else
        cout << s.substr(sa[it - begin(lcp)], *it) << '\n';
    return 0;
}
