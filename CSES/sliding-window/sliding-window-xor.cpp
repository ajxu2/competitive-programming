// created: 05-29-2025 Thu 11:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    V<int> stuff(n);
    stuff[0] = x;
    for (int i = 1; i < n; i++)
        stuff[i] = ((ll)a * stuff[i-1] + b) % c;
    int sum = accumulate(begin(stuff), begin(stuff) + k, 0, bit_xor<int>()), ans = sum;
    for (int i = k; i < n; i++) {
        sum ^= stuff[i] ^ stuff[i-k];
        ans ^= sum;
    }
    cout << ans << '\n';
    return 0;
}
