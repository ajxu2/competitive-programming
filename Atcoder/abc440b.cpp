// created: 01-15-2026 Thu 02:58 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(begin(a), end(a));
    for (int i = 0; i < 3; i++)
        cout << a[i][1] + 1 << ' ';
    cout << '\n';
    return 0;
}
