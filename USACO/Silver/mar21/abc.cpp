// created: 12-28-2021 Tue 10:55 PM

#include <bits/stdc++.h>
using namespace std;

// the array of numbers
vector<int> d;
// set of numbers that are already done
set<array<int, 3>> s;

bool works(int a, int b, int c) {
    // first make sure this hasn't already been done
    array<int, 3> search = {a, b, c};
    if (s.count(search)) return false;
    // figure out if d could work given a, b, c
    multiset<int> tmp = {a, b, c, a+b, b+c, a+c, a+b+c};
    bool ans = true;
    // is d a subset of tmp?
    for (int i : d) {
        if (tmp.find(i) != tmp.end()) {
            // remove it from the multiset to avoid repeats
            tmp.erase(tmp.find(i));
        } else {
            ans = false;
            break;
        }
    }
    // add it to the set of numbers that are already done
    if (ans) {
        s.insert(search);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    d.clear();
    d.resize(n);
    s.clear();
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    // well i guess we start spamming pairwise subtractions???
    vector<int> candidates = {d[0], d[1], d[2], d[3]};
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            candidates.push_back(d[j]-d[i]);
            // we're hopefully guaranteed to get all a, b, c
            // update: it got AC so i guess we were
        }
    }
    int ans = 0;
    // iterate through all candidates for A, B, C
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                vector<int> tmp = {candidates[i], candidates[j], candidates[k]};
                sort(tmp.begin(), tmp.end());
                if (works(tmp[0], tmp[1], tmp[2])) ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
