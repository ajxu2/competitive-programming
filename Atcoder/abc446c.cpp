// created: 02-23-2026 Mon 07:29 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, d; cin >> n >> d;
    V<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++)
            dq.push_back(i);
        for (int j = 0; j < b[i]; j++)
            dq.pop_front();
        while (!dq.empty() && dq.front() == i - d)
            dq.pop_front();
    }
    cout << ssize(dq) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
