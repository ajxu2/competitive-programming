// created: 07-11-2024 Thu 12:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    array<int, 3> a;
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) (*min_element(begin(a), end(a)))++;
    cout << a[0] * a[1] * a[2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
