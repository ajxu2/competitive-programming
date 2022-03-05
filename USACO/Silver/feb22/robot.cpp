#include <bits/stdc++.h>
using namespace std;

// this solution is extremely unmotivated and is basically copied from the editorial

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    array<int, 2> fin; cin >> fin[0] >> fin[1];
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    // get all subsets of each half
    vector<array<int, 3>> meet;
    for (long long test = 0; test < (1<<(n/2)); test++) {
        array<int, 3> tmp = {0, 0, 0};
        for (int i = 0; i < n/2; i++) {
            if (test&(1LL<<i)) {
                tmp[0] += a[i][0];
                tmp[1] += a[i][1];
                tmp[2]++;
            }
        }
        meet.push_back(tmp);
    }
    vector<array<int, 3>> middle;
    for (long long test = 0; test < (1<<((n+1)/2)); test++) {
        array<int, 3> tmp = {0, 0, 0};
        for (int i = 0; i < (n+1)/2; i++) {
            if (test&(1LL<<i)) {
                tmp[0] += a[i+n/2][0];
                tmp[1] += a[i+n/2][1];
                tmp[2]++;
            }
        }
        middle.push_back(tmp);
    }
    sort(meet.begin(), meet.end());
    sort(middle.begin(), middle.end());
#ifdef LOCAL
    cerr << "MEET\n";
    for (array<int, 3> i : meet) cerr << i[0] << " " << i[1] << " " << i[2] << ", ";
    cerr << "\n\n";
    cerr << "MIDDLE\n";
    for (array<int, 3> i : middle) cerr << i[0] << " " << i[1] << " " << i[2] << ", ";
    cerr << "\n\n";
#endif
    vector<long long> ans(n+1, 0);
    // precompute for middle - given some point, how many ways can we get to it using some number of moves?
    map<array<int, 2>, map<int, int>> pre;
    for (array<int, 3> i : middle) {
        array<int, 2> key = {i[0], i[1]};
        pre[key][i[2]]++;
    }
    // search
    for (array<int, 3> i : meet) {
        auto it = pre.find({fin[0]-i[0], fin[1]-i[1]});
        if (it != pre.end()) {
            for (pair<int, int> j : it->second) {
                ans[j.first+i[2]] += j.second;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}
