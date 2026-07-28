// created: 04-18-2026 Sat 09:03 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<int> f(n);
    for (int& i : f)
        cin >> i, i--;
    sort(begin(f), end(f));
    bool q1 = true;
    for (int i = 0; i < n - 1; i++)
        if (f[i] == f[i + 1])
            q1 = false;
    cout << (q1 ? "Yes" : "No") << '\n';
    V<bool> b(m, false);
    for (int i : f)
        b[i] = true;
    bool q2 = true;
    for (int i = 0; i < m; i++)
        if (!b[i])
            q2 = false;
    cout << (q2 ? "Yes" : "No") << '\n';
    return 0;
}
