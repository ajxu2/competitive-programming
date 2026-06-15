// created: 06-13-2026 Sat 09:44 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for (char i : s)
        if (isdigit(i))
            cout << i;
    cout << '\n';
    return 0;
}
