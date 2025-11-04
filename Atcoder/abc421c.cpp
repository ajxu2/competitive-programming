// created: 08-30-2025 Sat 08:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    V<int> a, b;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'A')
            a.push_back(i);
        else
            b.push_back(i);
    }
    ll res1 = 0;
    for (int i = 0; i < n; i++)
        res1 += abs(a[i] - 2 * i);
    ll res2 = 0;
    for (int i = 0; i < n; i++)
        res2 += abs(a[i] - 2 * i - 1);
    cout << min(res1, res2) << '\n';
    return 0;
}
