// created: 10-20-2023 Fri 01:11 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        V<int> a(n);
        for (int& i : a) {
            cin >> i; i %= 4;
        }
        if (accumulate(begin(a), end(a), 0, bit_xor<int>()) == 0) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}
