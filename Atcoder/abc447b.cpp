// created: 03-02-2026 Mon 08:26 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    array<int, 26> freq;
    freq.fill(0);
    for (char i : s)
        freq[i - 'a']++;
    int mx = *max_element(begin(freq), end(freq));
    string t;
    for (char i : s)
        if (freq[i - 'a'] != mx)
            t.push_back(i);
    cout << t << '\n';
    return 0;
}
