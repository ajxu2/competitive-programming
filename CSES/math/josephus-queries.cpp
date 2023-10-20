// created: 10-19-2023 Thu 03:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int uwu(int n, int k) {
    if (n == 1) return 1;
    if (k <= n/2) return 2 * k;
    if (n % 2 == 0) return 2 * uwu(n/2, k - n/2) - 1;
    else {
        int res = uwu(n/2 + 1, k - n/2);
        if (res == 1) return n;
        return 2 * res - 3;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        cout << uwu(n, k) << "\n";
    }
    return 0;
}
