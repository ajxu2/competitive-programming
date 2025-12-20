// created: 12-19-2025 Fri 11:23 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, k; cin >> n >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < k; i++)
            cout << n << " \n"[i == k - 1];
        return;
    }
    V<int> ans(k, 0);
    int free = 0;
    for (int i = 30; i >= 0; i--) {
        if ((n >> i) & 1) {
            int exclude = min(k - 1, free);
            for (int j = 0; j < k; j++)
                if (j != exclude)
                    ans[j] += 1 << i;
            free++;
        } else {
            int to_write = min(free, k);
            to_write -= to_write % 2;
            for (int j = 0; j < to_write; j++)
                ans[j] += 1 << i;
        }
    }
    for (int i = 0; i < k; i++)
        cout << ans[i] << " \n"[i == k - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
