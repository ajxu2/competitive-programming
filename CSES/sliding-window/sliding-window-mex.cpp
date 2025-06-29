// created: 06-14-2025 Sat 06:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    map<int, int> mp; // freq map
    set<int> excluded;
    for (int i = 0; i <= k; i++)
        excluded.insert(i);
    for (int i = 0; i < k; i++) {
        mp[a[i]]++;
        excluded.erase(a[i]);
    }
    cout << *begin(excluded) << ' ';
    for (int i = k; i < n; i++) {
        mp[a[i]]++;
        excluded.erase(a[i]);
        mp[a[i-k]]--;
        if (mp[a[i-k]] == 0)
            excluded.insert(a[i-k]);
        cout << *begin(excluded) << ' ';
    }
    cout << '\n';
    return 0;
}
