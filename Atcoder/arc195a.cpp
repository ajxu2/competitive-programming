// created: 03-23-2025 Sun 08:15 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    map<int, V<int>> pos;
    for (int i = 0; i < n; i++) pos[a[i]].push_back(i);
    // two subsequences that differ in one position
    int ptr = 0;
    V<int> pref(m), suf(m);
    for (int i = 0; i < m; i++) {
        while (ptr < n && a[ptr] != b[i]) ptr++;
        pref[i] = ptr;
        ptr++;
    }
    if (pref[m-1] == n) {
        cout << "No\n";
        return 0;
    }
    ptr = n - 1;
    for (int i = m-1; i >= 0; i--) {
        while (ptr >= 0 && a[ptr] != b[i]) ptr--;
        suf[i] = ptr;
        ptr--;
    }
    for (int i = 0; i < m; i++) {
        int lb = i == 0 ? 0 : pref[i-1] + 1;
        int ub = i == m-1 ? n : suf[i+1];
        // search for b[i] in [lb, ub)
        auto itl = lower_bound(begin(pos[b[i]]), end(pos[b[i]]), lb);
        auto itr = lower_bound(begin(pos[b[i]]), end(pos[b[i]]), ub);
        if (itr - itl >= 2) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
