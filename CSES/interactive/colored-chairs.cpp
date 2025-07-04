// created: 07-03-2025 Thu 02:16 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

bool qry_red(int i) {
    cout << "? " << i << endl;
    string res; cin >> res;
    return res == "R";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // just bsearch lol
    int n; cin >> n;
    bool first_red = qry_red(1);
    int l = 1, r = n;
    while (l < r) {
        int mid = midpoint(l, r + 1);
        if (first_red ^ qry_red(mid) ^ (mid % 2 == 1))
            l = mid;
        else
            r = mid - 1;
    }
    cout << "! " << l << endl;
    return 0;
}
