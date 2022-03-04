// created: 03-03-2022 Thu 08:33 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << "\n";
    return 0;
}
