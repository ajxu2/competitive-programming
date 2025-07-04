// created: 06-29-2025 Sun 11:59 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

bool qry(int y) {
    cout << "? " << y << endl;
    string s; cin >> s;
    return s == "YES";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int l = 1, r = 1'000'000'000;
    while (l < r) {
        int mid = midpoint(l, r);
        if (qry(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << "! " << l << endl;
    return 0;
}
