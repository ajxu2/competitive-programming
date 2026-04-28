// created: 04-25-2026 Sat 08:28 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

template<class T> T normalize(T a) {
    int mn = *min_element(begin(a), end(a));
    for (int& i : a)
        i -= mn;
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    map<array<int, 2>, int> cnt_ab, cnt_bc, cnt_ac;
    map<array<int, 3>, int> cnt_abc;
    array<int, 3> cur = {0, 0, 0};
    cnt_ab[{0, 0}]++;
    cnt_bc[{0, 0}]++;
    cnt_ac[{0, 0}]++;
    cnt_abc[{0, 0, 0}]++;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cur[s[i] - 'A']++;
        array<int, 2> ab = normalize(array<int, 2>{cur[0], cur[1]});
        array<int, 2> bc = normalize(array<int, 2>{cur[1], cur[2]});
        array<int, 2> ac = normalize(array<int, 2>{cur[0], cur[2]});
        array<int, 3> abc = normalize(cur);
        ans += i + 1 - cnt_ab[ab] - cnt_bc[bc] - cnt_ac[ac] + 2 * cnt_abc[abc];
        cnt_ab[ab]++;
        cnt_bc[bc]++;
        cnt_ac[ac]++;
        cnt_abc[abc]++;
    }
    cout << ans << '\n';
    return 0;
}
