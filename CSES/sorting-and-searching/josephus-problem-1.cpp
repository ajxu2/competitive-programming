// created: 08-20-2022 Sat 10:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n"; return 0;
    }
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    auto it = ++s.begin();
    while (s.size() > 1) {
        cout << *it << " ";
        it = s.erase(it); if (it == s.end()) it = s.begin();
        it++; if (it == s.end()) it = s.begin();
    }
    cout << *s.begin() << "\n";
    return 0;
}
