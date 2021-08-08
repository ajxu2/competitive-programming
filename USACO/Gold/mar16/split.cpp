// created: 07-27-2021 Tue 01:00 PM

#include <bits/stdc++.h>
using namespace std;

bool ycomp(const array<int, 2>& a, const array<int, 2>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int main() {
    ifstream cin("split.in");
    ofstream cout("split.out");
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end(), ycomp);
    long long one = a.back()[1] - a.front()[1];
    sort(a.begin(), a.end());
    one *= a.back()[0] - a.front()[0];
    map<int, long long> leftdp, rightdp, bottomdp, topdp;
    int mn = INT_MAX, mx = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i][1]);
        mx = max(mx, a[i][1]);
        leftdp[a[i][0]] = (long long)(mx-mn)*(a[i][0]-a.front()[0]);
    }
    mn = INT_MAX, mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mn = min(mn, a[i][1]);
        mx = max(mx, a[i][1]);
        rightdp[a[i][0]] = (long long)(mx-mn)*(a.back()[0]-a[i][0]);
    }
    sort(a.begin(), a.end(), ycomp);
    mn = INT_MAX, mx = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i][0]);
        mx = max(mx, a[i][0]);
        bottomdp[a[i][1]] = (long long)(mx-mn)*(a[i][1]-a.front()[1]);
    }
    mn = INT_MAX, mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mn = min(mn, a[i][0]);
        mx = max(mx, a[i][0]);
        topdp[a[i][1]] = (long long)(mx-mn)*(a.back()[1]-a[i][1]);
    }
    long long two = LLONG_MAX;
    for (pair<int, long long> i : leftdp) {
        auto it = rightdp.find(i.first);
        it++;
        if (it != rightdp.end()) {
            two = min(two, i.second + (*it).second);
        }
    }
    for (pair<int, long long> i : bottomdp) {
        auto it = topdp.find(i.first);
        it++;
        if (it != topdp.end()) {
            two = min(two, i.second + (*it).second);
        }
    }
    cout << one - two << "\n";
    return 0;
}
