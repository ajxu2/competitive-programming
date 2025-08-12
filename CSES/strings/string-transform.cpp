// created: 08-01-2025 Fri 12:32 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // I LOVE PHILLIP COMPEAU
    string s; cin >> s;
    int n = ssize(s);
    // do counting sort
    V<int> nxt(n);
    array<int, 128> cnt;
    cnt.fill(0);
    for (char i : s)
        cnt[i]++;
    for (int i = 1; i < 128; i++)
        cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; i--) {
        cnt[s[i]]--;
        nxt[cnt[s[i]]] = i;
    }
    string ans;
    int cur = nxt[0];
    do {
        ans.push_back(s[cur]);
        cur = nxt[cur];
    } while (s[cur] != '#');
    ans.erase(begin(ans));
    cout << ans << '\n';
    return 0;
}
