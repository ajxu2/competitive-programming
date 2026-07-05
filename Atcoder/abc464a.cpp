// created: 06-27-2026 Sat 09:17 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s), cnt_e = 0;
    for (char i : s)
        cnt_e += i == 'E';
    int cnt_w = n - cnt_e;
    cout << (cnt_e > cnt_w ? "East" : "West") << '\n';
    return 0;
}
