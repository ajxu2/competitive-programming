// created: 06-27-2026 Sat 09:23 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    V<V<array<int, 2>>> events(m);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int a, d, b; cin >> a >> d >> b; a--, d--, b--;
        events[d].push_back({a, b});
        freq[a]++;
    }
    for (int i = 0; i < m; i++) {
        for (auto [a, b] : events[i]) {
            freq[a]--;
            freq[b]++;
            if (freq[a] == 0)
                freq.erase(a);
        }
        cout << ssize(freq) << '\n';
    }
    return 0;
}
