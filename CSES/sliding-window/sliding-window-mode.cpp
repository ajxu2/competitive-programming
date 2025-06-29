// created: 06-14-2025 Sat 06:15 PM

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
    map<int, int> mp; // {number, frequency}
    set<pair<int, int>> se; // {-frequency, number}
    for (int i = 0; i < k; i++) {
        se.erase({-mp[a[i]], a[i]});
        mp[a[i]]++;
        se.insert({-mp[a[i]], a[i]});
    }
    cout << begin(se)->second << ' ';
    for (int i = k; i < n; i++) {
        se.erase({-mp[a[i]], a[i]});
        mp[a[i]]++;
        se.insert({-mp[a[i]], a[i]});
        se.erase({-mp[a[i-k]], a[i-k]});
        mp[a[i-k]]--;
        se.insert({-mp[a[i-k]], a[i-k]});
        cout << begin(se)->second << ' ';
    }
    cout << '\n';
    return 0;
}
