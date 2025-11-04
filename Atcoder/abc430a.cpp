// created: 11-01-2025 Sat 07:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (c >= a && d < b)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
