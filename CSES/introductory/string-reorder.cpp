// created: 05-13-2025 Tue 02:55 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = (int)s.length();
    array<int, 26> freq;
    freq.fill(0);
    for (char i : s)
        freq[i - 'A']++;
    V<int> ans;
    for (int i = 0; i < n; i++) {
        int to_add = -1;
        // get best letter
        for (int j = 0; j < 26; j++) {
            if (freq[j] > 0 && (ans.empty() || ans.back() != j)) {
                to_add = j;
                break;
            }
        }
        // but if there's a character that appears more than half, must pick
        for (int j = 0; j < 26; j++) {
            if (freq[j] > (n - i) / 2)
                to_add = j;
        }
        if (!ans.empty() && ans.back() == to_add) {
            cout << "-1\n";
            return 0;
        }
        ans.push_back(to_add);
        freq[to_add]--;
    }
    for (int i : ans)
        cout << (char)(i + 'A');
    cout << '\n';
    return 0;
}
