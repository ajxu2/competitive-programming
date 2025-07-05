// created: 07-05-2025 Sat 12:54 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

V<int> xor_pyramid_diagonal(V<int> a) {
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < ssize(a); j++)
            if ((j >> i) & 1)
                a[j] ^= a[j ^ (1 << i)];
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    // get diagonal, take last k, get diagonal of that
    V<int> b = xor_pyramid_diagonal(a);
    V<int> c(end(b) - k, end(b));
    V<int> d = xor_pyramid_diagonal(c);
    for (int i = 0; i < k; i++)
        cout << d[i] << " \n"[i == k-1];
    return 0;
}
