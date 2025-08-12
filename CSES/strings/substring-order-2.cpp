// created: 08-11-2025 Mon 11:28 AM

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
    V<int> lcp(n, 0);
    int last_lcp = 0;
    for (int i = 0; i < n; i++) {
        int idx = inv[i];
        if (idx == 0) {
            last_lcp = 0;
            continue;
        }
        if (last_lcp > 0)
            lcp[idx] = last_lcp - 1;
        while (s[i + lcp[idx]] == s[sa[idx-1] + lcp[idx]])
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
    // binary search on the answer
    auto ith_distinct_substring = [&](ll i) -> array<int, 2> {
        int j = 0;
        for (; j < n; j++) {
            int new_substrings = n - sa[j] - lcp[j];
            if (i >= new_substrings)
                i -= new_substrings;
            else
                break;
        }
        return {j, (int)(i + lcp[j])};
    };
    auto cnt_leq = [&](array<int, 2> ar) -> ll {
        auto [idx1, idx2] = ar;
        ll res = 0;
        for (int i = 0; i < idx1; i++)
            res += n - sa[i];
        int len = idx2 + 1;
        res += len;
        for (int i = idx1 + 1; i < n; i++) {
            len = min(len, lcp[i]);
            res += len;
        }
        return res;
    };
    ll num_distinct_substrings = (ll)n * (n + 1) / 2
        - accumulate(begin(lcp), end(lcp), 0LL);
    // find first cnt_leq(ith_distinct_substring(i)) >= k
    ll l = 0, r = num_distinct_substrings - 1;
    while (l < r) {
        ll mid = midpoint(l, r);
        if (cnt_leq(ith_distinct_substring(mid)) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    auto [idx1, idx2] = ith_distinct_substring(l);
    cout << s.substr(sa[idx1], idx2 + 1) << '\n';
    return 0;
}
