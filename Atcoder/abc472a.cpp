// created: 08-22-2026 Sat 08:24 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for (char& i : s)
        if (i != 'A')
            i = '.';
    cout << s << '\n';
    return 0;
}
