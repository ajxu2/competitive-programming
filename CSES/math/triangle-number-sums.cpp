// created: 05-21-2025 Wed 02:50 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const ll MAXN = 1'000'000'000'000;

ll nth_tri(ll i) { return i * (i + 1) / 2; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    V<ll> tri;
    for (ll i = 1; nth_tri(i) <= MAXN; i++)
        tri.push_back(nth_tri(i));
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        if (binary_search(begin(tri), end(tri), n)) {
            cout << "1\n";
        } else {
            int r = ssize(tri) - 1;
            bool found = false;
            for (int l = 0; l <= r; l++) {
                while (r >= 0 && tri[l] + tri[r] > n)
                    r--;
                if (r >= 0 && tri[l] + tri[r] == n)
                    found = true;
            }
            if (found)
                cout << "2\n";
            else
                cout << "3\n";
        }
    }
    return 0;
}
