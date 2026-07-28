// created: 07-26-2026 Sun 05:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    if (n % 2 == 1 || a % 2 == b % 2) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    bool transpose = false;
    if (a % 2 == 0) {
        transpose = true;
        swap(a, b);
    }
    string ans;
    for (int i = 0; i < a / 2; i++) {
        ans.append(n - 1, 'R');
        ans.push_back('D');
        ans.append(n - 1, 'L');
        ans.push_back('D');
    }
    for (int i = 0; i < b / 2 - 1; i++)
        ans.append("DRUR");
    ans.append("DR");
    for (int i = 0; i < (n - b) / 2; i++)
        ans.append("RURD");
    for (int i = 0; i < (n - a) / 2; i++) {
        ans.push_back('D');
        ans.append(n - 1, 'L');
        ans.push_back('D');
        ans.append(n - 1, 'R');
    }
    map<char, char> convert = {{'R', 'D'}, {'D', 'R'}, {'L', 'U'}, {'U', 'L'}};
    if (transpose)
        for (char& c : ans)
            c = convert[c];
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
