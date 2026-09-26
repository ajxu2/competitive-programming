// created: 09-26-2026 Sat 09:11 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<int> ans;
    for (int i = 0; i < n; i++) {
        bool good = true;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            good &= abs(a[i] - a[j]) >= d;
        }
        if (good)
            ans.push_back(i);
    }
    cout << ssize(ans) << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
    return 0;
}
