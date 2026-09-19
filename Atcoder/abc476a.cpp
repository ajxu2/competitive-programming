// created: 09-19-2026 Sat 11:49 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    if (s.back() == 'e')
        s.push_back('r');
    else
        s.append("er");
    cout << s << '\n';
    return 0;
}
