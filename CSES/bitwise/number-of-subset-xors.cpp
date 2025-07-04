// created: 07-03-2025 Thu 11:45 PM

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
    // gaussian eliminate ts
    int pivoted = 0;
    for (int i = 30; i >= 0; i--) {
        bool found = false;
        for (int j = pivoted; j < n; j++) {
            if ((a[j] >> i) & 1) {
                swap(a[pivoted], a[j]);
                found = true;
                break;
            }
        }
        if (!found)
            continue;
        for (int j = 0; j < n; j++) {
            if (j != pivoted && ((a[j] >> i) & 1))
                a[j] ^= a[pivoted];
        }
        pivoted++;
    }
    cout << (1 << pivoted) << '\n';
    return 0;
}
