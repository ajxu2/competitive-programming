// created: 07-03-2025 Thu 02:28 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int qry(int i, int j) {
    cout << i << ' ' << j << endl;
    int res; cin >> res;
    if (res == 0)
        exit(0);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    // just do insertion sort
    if (n == 1) {
        qry(1, 1);
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int after_flip = qry(1, i + 1); // i(i+1)/2 - dist
        int before_flip = qry(1, i + 1); // dist
        int dist = (before_flip - after_flip + i * (i + 1) / 2) / 2;
        if (dist > 0) {
            qry(i - dist + 1, i + 1);
            qry(i - dist + 2, i + 1);
        }
    }
    return 0;
}
