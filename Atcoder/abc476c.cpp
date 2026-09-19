// created: 09-19-2026 Sat 11:45 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> mx;
    for (int i = 0; i < 3; i++)
        mx.push_back(a[i]);
    sort(begin(mx), end(mx), greater<int>());
    cout << mx[2] << '\n';
    for (int i = 3; i < n; i++) {
        mx.push_back(a[i]);
        sort(begin(mx), end(mx), greater<int>());
        mx.pop_back();
        cout << mx[2] << '\n';
    }
    return 0;
}
