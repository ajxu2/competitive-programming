// created: 08-08-2026 Sat 09:00 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> freq(n, 0);
    for (int i = 0; i < n; i++) {
        int c; cin >> c; c--;
        freq[c]++;
    }
    cout << n - *max_element(begin(freq), end(freq)) << '\n';
    return 0;
}
