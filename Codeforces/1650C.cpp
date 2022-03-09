// created: 03-08-2022 Tue 08:53 AM

#include <bits/stdc++.h>
using namespace std;

struct Pt {
    int x, w, n;
};

bool cmp1(const Pt& a, const Pt& b) {
    return a.x < b.x;
}

bool cmp2(const Pt& a, const Pt& b) {
    if (a.w == b.w) return a.x < b.x;
    return a.w < b.w;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Pt> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].x >> a[i].w;
        a[i].n = i+1;
    }
    // sort by weight and take the first 2*n
    sort(a.begin(), a.end(), cmp2);
    // sort first 2*n by coordinate
    sort(a.begin(), a.begin()+2*n, cmp1);
    int ans1 = 0;
    for (int i = 0; i < 2*n; i++) ans1 += a[i].w;
    vector<array<int, 2>> ans(n);
    for (int i = 0; i < n; i++) ans[i][0] = a[i].n;
    for (int i = n-1; i >= 0; i--) ans[i][1] = a[2*n-1-i].n;
    cout << ans1 << "\n";
    for (int i = 0; i < n; i++) cout << ans[i][0] << " " << ans[i][1] << "\n";
    cout << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
