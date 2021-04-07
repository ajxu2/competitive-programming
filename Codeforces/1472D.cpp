#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        long long alice = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && a.back() % 2 == 0) {
                alice += a.back();
            } else if (i % 2 == 1 && a.back() % 2 == 1) {
                bob += a.back();
            }
            a.pop_back();
        }
        if (alice > bob) {
            cout << "Alice\n";
        } else if (bob > alice) {
            cout << "Bob\n";
        } else {
            cout << "Tie\n";
        }
    }
    return 0;
}
