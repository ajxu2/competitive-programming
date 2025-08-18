// created: 08-17-2025 Sun 08:43 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // sort double sided cards by front
    // clearly, person who gets the last one wins
    // suppose last one has front c, and second last is (a, b)
    // if c < b then second last acts like a single sided card,
    // otherwise whoever gets the second last wins
    // then just repeat this
    int n, m; cin >> n >> m;
    V<array<int, 2>> a(n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][i];
    sort(begin(a), end(a));
    V<int> single(m);
    for (int& i : single)
        cin >> i;
    while (ssize(a) >= 2) {
        if (a[ssize(a) - 1][0] < a[ssize(a) - 2][1]) {
            single.push_back(a[ssize(a) - 2][0]);
            a.erase(begin(a) + ssize(a) - 2);
        } else {
            a.pop_back();
        }
    }
    sort(begin(single), end(single));
    int flip = lower_bound(begin(single), end(single), a.front()[0])
        - begin(single);
    cout << (flip % 2 == 0 ? "First" : "Second") << '\n';
    return 0;
}
