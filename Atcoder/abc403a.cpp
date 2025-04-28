// created: 04-27-2025 Sun 08:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    int sum = 0;
    for (int i = 0; i < n; i += 2) sum += a[i];
    cout << sum << '\n';
    return 0;
}
