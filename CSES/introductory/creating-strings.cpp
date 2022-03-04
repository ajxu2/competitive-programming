// created: 03-03-2022 Thu 09:22 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    set<string> visited;
    do {
        visited.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << visited.size() << "\n";
    for (string i : visited) cout << i << "\n";
    return 0;
}
