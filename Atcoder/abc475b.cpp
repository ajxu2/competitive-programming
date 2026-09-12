// created: 09-12-2026 Sat 09:56 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int one = 0, ten = 0, hundred = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int change = ((-a % 1000) + 1000) % 1000;
        one += change % 10;
        ten += (change / 10) % 10;
        hundred += change / 100;
    }
    cout << one << ' ' << ten << ' ' << hundred << '\n';
    return 0;
}
