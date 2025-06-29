// created: 06-14-2025 Sat 06:11 PM

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
    map<int, int> mp;
    for (int i = 0; i < k; i++)
        mp[a[i]]++;
    cout << size(mp) << ' ';
    for (int i = k; i < n; i++) {
        mp[a[i]]++;
        mp[a[i-k]]--;
        if (mp[a[i-k]] == 0)
            mp.erase(a[i-k]);
        cout << size(mp) << ' ' ;
    }
    cout << '\n';
    return 0;
}
