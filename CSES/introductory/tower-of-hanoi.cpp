// created: 03-03-2022 Thu 08:37 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    // stolen from wikipedia i have no idea how/why this works
    cout << (1<<n)-1 << "\n";
    vector<vector<int>> a(4);
    for (int i = n; i >= 1; i--) a[1].push_back(i);
    if (n % 2 == 0) {
        for (int i = 0; i < (1<<n)-1; i++) {
            int f, t;
            if (i % 3 == 0) f = 1, t = 2;
            else if (i % 3 == 1) f = 1, t = 3;
            else f = 2, t = 3;
            if (a[f].size() == 0 || (a[t].size() != 0 && a[f].back() > a[t].back())) swap(f, t);
            int tmp = a[f].back();
            a[f].pop_back();
            a[t].push_back(tmp);
            cout << f << " " << t << "\n";
        }
    } else {
        for (int i = 0; i < (1<<n)-1; i++) {
            int f, t;
            if (i % 3 == 0) f = 1, t = 3;
            else if (i % 3 == 1) f = 1, t = 2;
            else f = 2, t = 3;
            if (a[f].size() == 0 || (a[t].size() != 0 && a[f].back() > a[t].back())) swap(f, t);
            int tmp = a[f].back();
            a[f].pop_back();
            a[t].push_back(tmp);
            cout << f << " " << t << "\n";
        }
    }
    return 0;
}
