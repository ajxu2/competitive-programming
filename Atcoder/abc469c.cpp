// created: 08-01-2026 Sat 12:11 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    V<int> ans;
    for (int i = 0; i < n; i++)
        if (s[i] == 'x')
            ans.push_back(i + 1);
    for (int i : ans)
        cout << i << '\n';
    for (int i = 0; i < n - ssize(ans); i++)
        cout << n << '\n';
    return 0;
}
