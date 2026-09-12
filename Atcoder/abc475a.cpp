// created: 09-12-2026 Sat 09:58 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = ssize(s);
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1)
            cout << 'o';
    }
    cout << '\n';
    return 0;
}
