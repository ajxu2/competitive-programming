// created: 07-05-2025 Sat 12:51 PM

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
    // by lucas theorem, suffices to do sos dp
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < n; j++)
            if ((j >> i) & 1)
                a[j] ^= a[j ^ (1 << i)];
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n-1];
    return 0;
}
