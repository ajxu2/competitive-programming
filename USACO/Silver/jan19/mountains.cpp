// created: 05-22-2021 Sat 10:07 PM

#include <bits/stdc++.h>
using namespace std;

struct Mountain {
    int x, y;
    bool operator<(const Mountain& b) {
        if (x - y == b.x - b.y) {
            return x + y > b.x + b.y;
        }
        return x - y < b.x - b.y;
    }
};

int main() {
#ifndef LOCAL
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
#endif
    int n; 
    cin >> n;
    vector<Mountain> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end());
    int ans = n;
    int maxr = a[0].x + a[0].y;
    for (int i = 1; i < n; i++) {
        if (a[i].x + a[i].y <= maxr) {
            ans--;
        }
        maxr = max(a[i].x + a[i].y, maxr);
    }
    cout << ans << "\n";
    return 0;
}
