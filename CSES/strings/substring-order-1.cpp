// created: 08-03-2025 Sun 03:04 PM

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
    int n = ssize(s);
    V<int> sa = suffix_array(s);
    V<int> lcp = lcp_array(s, sa);
    ll k; cin >> k;
    int i = 0;
    for (i = 0; i < n; i++) {
        int new_substrings = n - sa[i];
        if (i > 0)
            new_substrings -= lcp[i-1];
        if (k > new_substrings)
            k -= new_substrings;
        else
            break;
    }
    int len = k;
    if (i > 0)
        len += lcp[i-1];
    cout << s.substr(sa[i], len) << '\n';
    return 0;
}
