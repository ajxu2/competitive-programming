// created: 12-23-2021 Thu 05:31 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    vector<array<int, 2>> patches(k);
    for (int i = 0; i < k; i++) {
        // note: multiply indices by 2 to make calculations easier later
        int a, b;
        cin >> a >> b;
        patches[i][0] = 2*a;
        patches[i][1] = b;
    }
    sort(patches.begin(), patches.end());
    vector<int> nhoj(m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        nhoj[i] = 2*a;
    }
    sort(nhoj.begin(), nhoj.end());
    // Nhoj's cows partition the line into m+1 intervals
    // in a given interval, 1 cow gets some of the patches
    // and 2 cows get all of the patches
    vector<long long> onecow(m+1, 0);
    vector<long long> twocow(m+1, 0);
    // left and right intervals - get all the patches with one cow
    array<int, 2> search = {nhoj[0], 0};
    auto it = lower_bound(patches.begin(), patches.end(), search);
    for (auto i = patches.begin(); i != it; i++) {
        onecow[0] += (*i)[1];
        twocow[0] += (*i)[1];
    }
    search = {nhoj[m-1], 0};
    it = lower_bound(patches.begin(), patches.end(), search);
    for (auto i = it; i != patches.end(); i++) {
        onecow[m] += (*i)[1];
        twocow[m] += (*i)[1];
    }
    // in any other interval, one cow always gets a range of (b-a)/2
    // where a and b are the endpoints
    // figure out which range has the highest tastiness
    for (int i = 1; i < m; i++) {
        // calculate for one cow
        int range = (nhoj[i] - nhoj[i-1])/2;
        search = {nhoj[i-1], 0};
        auto it1 = lower_bound(patches.begin(), patches.end(), search);
        if (it1 == patches.end()) continue;
        auto it2 = it1;
        long long tmp = 0;
        while (it1 != patches.end() && (*it1)[0] <= nhoj[i]) {
            while (it2 != patches.end() && (*it2)[0] < nhoj[i] && (*it2)[0] < (*it1)[0] + range) {
                tmp += (*it2)[1];
                it2++;
            } 
            onecow[i] = max(tmp, onecow[i]);
            tmp -= (*it1)[1];
            it1++;
        }
        // calculate for two cows
        it1 = lower_bound(patches.begin(), patches.end(), search);
        while (it1 != patches.end() && (*it1)[0] <= nhoj[i]) {
            twocow[i] += (*it1)[1];
            it1++;
        }
    }
    vector<long long> profits = onecow;
    for (int i = 0; i <= m; i++) {
        profits.push_back(twocow[i] - onecow[i]);
    }
    sort(profits.begin(), profits.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (2*m+1-i >= 0) {
            ans += profits[2*m+1-i];
        }
    }
    cout << ans << "\n";
    return 0;
}
