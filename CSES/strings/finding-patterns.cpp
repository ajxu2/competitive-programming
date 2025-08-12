// created: 05-17-2024 Fri 01:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    s.push_back('#');
    int m = ssize(s);
    // construct suffix array
    V<int> rnk(m);
    for (int i = 0; i < m; i++)
        rnk[i] = (int)s[i];
    V<array<int, 3>> stuff(m);
    for (int i = 1; i < m; i <<= 1) {
        for (int j = 0; j < m; j++) {
            stuff[j] = {rnk[j], rnk[(j + i) % m], j};
        }
        sort(begin(stuff), end(stuff));
        array<int, 2> lst = {-1, -1};
        int cur = 0;
        for (array<int, 3>& j : stuff) {
            if (lst != array<int, 2>{j[0], j[1]}) {
                lst = {j[0], j[1]};
                cur++;
            }
            rnk[j[2]] = cur;
        }
    }
    V<int> suffix_array(m);
    for (int i = 0; i < m; i++)
        suffix_array[i] = stuff[i][2];
    s += s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        // binary search on suffix array
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = midpoint(l, r + 1);
            if (t < s.substr(suffix_array[mid], ssize(t)))
                r = mid - 1;
            else
                l = mid;
        }
        bool found = t == s.substr(suffix_array[l], ssize(t));
        cout << (found ? "YES" : "NO") << '\n';
    }
    return 0;
}
