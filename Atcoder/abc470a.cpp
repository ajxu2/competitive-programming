// created: 08-08-2026 Sat 09:01 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0)
            cout << "Fizz";
        else
            cout << i;
        cout << '\n';
    }
    return 0;
}
