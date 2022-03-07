// created: 03-06-2022 Sun 11:30 PM

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int w, x, v, n;
    bool operator<(const Cow& b) { return x < b.x; }
    bool operator>(const Cow& b) { return x > b.x; }
};

int main() {
#ifndef LOCAL
    ifstream cin("meetings.in");
    ofstream cout("meetings.out");
#endif
    int n, l; cin >> n >> l;
    vector<Cow> a(n);
    int sumWeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].x >> a[i].v;
        a[i].n = i;
        sumWeight += a[i].w;
    }
    sort(a.begin(), a.end());
    // positions of the cows that are going left/right
    vector<int> goingLeft, goingRight;
    for (int i = 0; i < n; i++) {
        if (a[i].v == -1) goingLeft.push_back(a[i].x);
        else goingRight.push_back(a[i].x);
    }
    // {time, weight}
    vector<array<int, 2>> ends;
    for (int i = 0; i < goingLeft.size(); i++) {
        ends.push_back({goingLeft[i], a[i].w});
    }
    for (int i = 0; i < goingRight.size(); i++) {
        ends.push_back({l-goingRight[i], a[goingLeft.size()+i].w});
    }
    sort(ends.begin(), ends.end());
    // get the time when at least half the weight is at the barns
    int ptr = 0, thisWeight = 0;
    while (thisWeight < (sumWeight+1)/2) {
        thisWeight += ends[ptr][1];
        ptr++;
    }
    ptr--;
    int t = ends[ptr][0];
    // binary search for how many meetings there will be for each cow going right
    int ans = 0;
    for (int i = 0; i < goingRight.size(); i++) {
        auto it1 = lower_bound(goingLeft.begin(), goingLeft.end(), goingRight[i]);
        auto it2 = upper_bound(goingLeft.begin(), goingLeft.end(), goingRight[i]+2*t);
        ans += distance(it1, it2);
    }
    cout << ans << "\n";
    return 0;
}
