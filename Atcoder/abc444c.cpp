// created: 02-07-2026 Sat 07:47 AM

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
    sort(begin(a), end(a));
    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }
    if (n % 2 == 1) {
        cout << a[n - 1] << '\n';
        return 0;
    }
    bool good = true;
    int l = a[n - 1];
    int ptr = n - 1;
    while (ptr >= 0 && a[ptr] == l)
        ptr--;
    if (ptr % 2 != 0) {
        for (int i = 0; i <= ptr; i++)
            if (a[i] + a[ptr - i] != l)
                good = false;
        if (good)
            cout << l << ' ';
    }
    good = true;
    l = a[0] + a[n - 1];
    for (int i = 0; i < n; i++)
        if (a[i] + a[n - i - 1] != l)
            good = false;
    if (good)
        cout << l;
    cout << '\n';
    return 0;
}
