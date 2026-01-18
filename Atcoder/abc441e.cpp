// created: 01-17-2026 Sat 07:35 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    V<int> level(n);
    int cur = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            cur++;
        else if (s[i] == 'B')
            cur--;
        level[i] = cur;
    }
    V<int> freq(2 * n + 1, 0);
    for (int i : level)
        freq[i]++;
    ll sfx = 0;
    for (int i = n + 1; i < 2 * n + 1; i++)
        sfx += freq[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sfx;
        freq[level[i]]--;
        if (s[i] == 'A')
            sfx--;
        if (s[i] == 'A') {
            sfx -= freq[level[i]];
        } else if (s[i] == 'B') {
            sfx += freq[level[i] + 1];
        }
    }
    cout << ans << '\n';
    return 0;
}
