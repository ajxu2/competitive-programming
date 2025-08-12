// created: 07-31-2025 Thu 09:09 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    string t = "#";
    for (char i : s) {
        t.push_back(i);
        t.push_back('#');
    }
    int n = ssize(t);
    // manacherrrrrrrr
    V<int> man(n, 0);
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (i < r)
            man[i] = min(man[2 * l - i], r - i);
        while (0 <= i - man[i] && i + man[i] < n
            && t[i - man[i]] == t[i + man[i]])
            man[i]++;
        if (i + man[i] > r)
            l = i, r = i + man[i];
    }
    // now it's just an intervals problem trust
    V<V<int>> stuff(n+1);
    for (int i = 0; i < n; i++)
        stuff[i + man[i]].push_back(i);
    set<int> se;
    V<int> ans(n);
    for (int i = 0; i < n; i++) {
        se.insert(i);
        for (int j : stuff[i])
            se.erase(j);
        ans[i] = i - *begin(se) + 1;
    }
    for (int i = 1; i < n; i += 2)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
