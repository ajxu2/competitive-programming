// created: 10-20-2022 Thu 01:47 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// https://codeforces.com/blog/entry/97919?#comment-870891 this is too smart and is way better than the editorial sol...

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> ans(n+2, 0);
    map<int, bool> intervals; // start of each interval; false for last modification on L; true for last modification on R
    intervals[0] = false;
    for (int i : a) {
        auto it = --intervals.lower_bound(i); // the interval we landed in
        if (it->second) {
            ans[i]++; ans[next(it)->first]--;
        }
        it->second = true;
        intervals[i] = false;
    }
    for (int i = 1; i <= n; i++) ans[i] += ans[i-1];
    for (int i = 0; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}
