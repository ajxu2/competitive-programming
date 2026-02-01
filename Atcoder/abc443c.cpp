// created: 01-31-2026 Sat 12:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    int ptr = 0;
    int time_closed = 0;
    while (ptr < n) {
        int close_time = a[ptr];
        time_closed += min(100, t - close_time);
        while (ptr < n && a[ptr] < close_time + 100)
            ptr++;
    }
    cout << t - time_closed << '\n';
    return 0;
}
