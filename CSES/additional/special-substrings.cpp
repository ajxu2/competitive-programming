// created: 10-29-2024 Tue 12:45 AM
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ull> dist(1, 10'000'000'000'000'000LL);
    V<ull> hsh(26);
    for (ull& i : hsh) i = dist(rng);
    string s; cin >> s;
    V<bool> used(26, false);
    for (char i : s) used[i - 'a'] = true;
    ull sum = 0;
    for (int i = 0; i < 26; i++) if (used[i]) sum += hsh[i];
    map<ull, int> mp;
    ull pref = 0; mp[0] = 1;
    ull ans = 0;
    for (char i : s) {
        pref += hsh[i - 'a']; pref %= sum;
        ans += mp[pref];
        mp[pref]++;
    }
    cout << ans << '\n';
    return 0;
}
