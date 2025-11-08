// created: 11-08-2025 Sat 07:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int h, b; cin >> h >> b;
    cout << max(0, h - b) << '\n';
    return 0;
}
