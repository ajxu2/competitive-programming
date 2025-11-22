// created: 11-22-2025 Sat 06:56 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, z; cin >> a >> b >> z;
    int thing = a - z * b;
    if (thing >= 0 && thing % (z - 1) == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
