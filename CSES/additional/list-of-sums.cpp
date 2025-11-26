// created: 11-25-2025 Tue 04:25 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int m = n * (n - 1) / 2;
    V<ll> b(m);
    for (ll& i : b)
        cin >> i;
    sort(begin(b), end(b));
    // b[0] = a[0] + a[1]
    // b[1] = a[0] + a[2]
    // brute force over which value is a[1] + a[2]
    for (int i = 2; i < m; i++) {
        ll sum = b[0] + b[1] + b[i];
        if (sum % 2 != 0)
            continue;
        sum /= 2;
        V<ll> a(n);
        a[0] = sum - b[i];
        a[1] = sum - b[1];
        a[2] = sum - b[0];
        if (a[0] < 1 || a[1] < 1 || a[2] < 1)
            continue;
        multiset<ll> remaining;
        for (int j = 2; j < m; j++)
            if (j != i)
                remaining.insert(b[j]);
        for (int j = 3; j < n; j++) {
            a[j] = *begin(remaining) - a[0];
            for (int k = 0; k < j; k++) {
                auto it = remaining.find(a[k] + a[j]);
                if (it == end(remaining))
                    goto fail;
                remaining.erase(it);
            }
        }
        for (int j = 0; j < n; j++)
            cout << a[j] << " \n"[j == n-1];
        break;
        fail:;
    }
    return 0;
}
