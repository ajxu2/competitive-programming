#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> diffs;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (lights.empty()) {
            lights.insert(temp);
            diffs.insert(temp);
            diffs.insert(x - temp);
        } else {
            auto it = lights.lower_bound(temp);
            if (it == lights.end()) {
                diffs.erase(diffs.find(x - *prev(it)));
                diffs.insert(temp - *prev(it));
                diffs.insert(x - temp);
            } else if (it == lights.begin()) {
                diffs.erase(diffs.find(*it));
                diffs.insert(temp);
                diffs.insert(*it - temp);
            } else {
                diffs.erase(diffs.find(*it - *prev(it)));
                diffs.insert(temp - *prev(it));
                diffs.insert(*it - temp);
            }
            lights.insert(temp);
        }
        cout << *(prev(diffs.end())) << " ";
    }
    cout << "\n";
    return 0;
}
