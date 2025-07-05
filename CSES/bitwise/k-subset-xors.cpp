// created: 07-04-2025 Fri 03:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
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
    int dim_ker = n - pivoted;
    if (dim_ker > 20) {
        for (int i = 0; i < k; i++)
            cout << "0 ";
        cout << '\n';
        return 0;
    }
    V<int> ans;
    for (int mask = 0; ssize(ans) < k; mask++) {
        int v = 0;
        for (int i = 0; i <= 30; i++) {
            if ((mask >> i) & 1) {
                v ^= a[pivoted - i - 1];
            }
        }
        for (int i = 0; i < (1 << dim_ker); i++)
            ans.push_back(v);
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
