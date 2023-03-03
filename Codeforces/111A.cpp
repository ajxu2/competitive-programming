#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    int n, y; ll x; cin >> n >> x >> y;
    ll first = y-(n-1);
    if (first <= 0 || first*first+(n-1) < x) cout << "-1\n";
    else {
        cout << first << "\n";
        for (int i = 1; i < n; i++) cout << "1\n";
    }
    return 0;
}
