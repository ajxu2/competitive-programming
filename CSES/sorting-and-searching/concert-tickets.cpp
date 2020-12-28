#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> tickets;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        tickets.insert(temp);
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        auto it = tickets.upper_bound(temp);
        if (it == tickets.begin()) {
            cout << -1;
        } else {
            it--;
            cout << *it;
            tickets.erase(it);
        }
        cout << "\n";
    }
    return 0;
}
