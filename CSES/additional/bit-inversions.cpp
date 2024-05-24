// created: 05-22-2024 Wed 04:22 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = sz(s);
    map<int, int> starts; multiset<int> diffs;
    int lst = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[lst]) {
            starts[lst] = i - lst;
            lst = i;
        }
    }
    starts[lst] = n - lst;
    for (pair<int, int> i : starts) diffs.insert(i.second);
    int m; cin >> m;
    while (m--) {
        int x; cin >> x; x--;
        if (x == 0) {
            if (starts.contains(1)) {
                // 01... -> 11...
                int len = starts[1]; starts.erase(1); starts[0] = len + 1;
                diffs.erase(diffs.find(1)); diffs.erase(diffs.find(len)); diffs.insert(len + 1);
            } else {
                // 11... -> 01...
                int len = starts[0]; starts[0] = 1; starts[1] = len - 1;
                diffs.erase(diffs.find(len)); diffs.insert(1); diffs.insert(len - 1);
            }
        } else if (starts.contains(x) && starts.contains(x+1)) {
            // 010 -> 000
            int pre = prev(starts.find(x))->first;
            int len1 = starts[pre], len2 = starts[x+1];
            starts[pre] = len1 + 1 + len2; starts.erase(x); starts.erase(x+1);
            diffs.erase(diffs.find(len1)); diffs.erase(diffs.find(1)); diffs.erase(diffs.find(len2));
            diffs.insert(len1 + 1 + len2);
        } else if (starts.contains(x)) {
            // 011 -> 001
            int pre = prev(starts.find(x))->first;
            int len1 = starts[pre], len2 = starts[x];
            starts[pre]++; starts.erase(x); if (x != n-1) starts[x+1] = len2 - 1;
            diffs.erase(diffs.find(len1)); diffs.erase(diffs.find(len2));
            diffs.insert(len1 + 1); if (len2 > 1) diffs.insert(len2 - 1);
        } else if (starts.contains(x+1)) {
            // 001 -> 011
            int pre = prev(starts.find(x+1))->first;
            int len1 = starts[pre], len2 = starts[x+1];
            starts[pre]--; starts.erase(x+1); starts[x] = len2 + 1;
            diffs.erase(diffs.find(len1)); diffs.erase(diffs.find(len2));
            diffs.insert(len1 - 1); diffs.insert(len2 + 1);
        } else {
            // 000 -> 010
            int pre = prev(starts.upper_bound(x))->first;
            int len = starts[pre];
            starts[pre] = x - pre; starts[x] = 1; if (x != n-1) starts[x+1] = len - (x - pre) - 1;
            diffs.erase(diffs.find(len));
            diffs.insert(x - pre); diffs.insert(1); if (x != n-1) diffs.insert(len - (x - pre) - 1);
        }
        cout << *prev(end(diffs)) << " \n"[m == 0];
    }
    return 0;
}
