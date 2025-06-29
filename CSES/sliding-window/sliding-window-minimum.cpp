// created: 06-14-2025 Sat 05:51 PM

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
    deque<int> minq;
    for (int i = 0; i < k; i++) {
        while (!empty(minq) && stuff[i] <= stuff[minq.back()])
            minq.pop_back();
        minq.push_back(i);
    }
    int ans = stuff[minq.front()];
    for (int i = k; i < n; i++) {
        while (!empty(minq) && stuff[i] <= stuff[minq.back()])
            minq.pop_back();
        minq.push_back(i);
        if (minq.front() == i - k)
            minq.pop_front();
        ans ^= stuff[minq.front()];
    }
    cout << ans << '\n';
    return 0;
}
