// created: 03-04-2025 Tue 01:05 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    // mfw linguistics
    string s; cin >> s;
    s.push_back('$');
    int a, b, ab, ba; cin >> a >> b >> ab >> ba;
    string cur = "";
    priority_queue<int, V<int>, greater<int>> ab_alt, ba_alt;
    int odd_alt = 0, cnt_a = 0, cnt_b = 0;
    for (char i : s) {
        if (i == 'A') cnt_a++;
        else if (i == 'B') cnt_b++;
        if (!empty(cur) && (cur.back() == i || i == '$')) {
            // split
            if (ssize(cur) % 2 == 0) {
                if (cur.front() == 'A') ab_alt.push(ssize(cur) / 2);
                else ba_alt.push(ssize(cur) / 2);
            } else odd_alt += ssize(cur) / 2;
            cur = "";
        }
        cur.push_back(i);
    }
    int twos_used = 0;
    // use ab
    while (!empty(ab_alt) && ab > 0) {
        int nxt = ab_alt.top();
        ab_alt.pop();
        int sub = min(ab, nxt);
        ab -= sub; nxt -= sub;
        twos_used += sub;
        if (nxt > 0) ab_alt.push(nxt);
    }
    // use ba
    while (!empty(ba_alt) && ba > 0) {
        int nxt = ba_alt.top();
        ba_alt.pop();
        int sub = min(ba, nxt);
        ba -= sub; nxt -= sub;
        twos_used += sub;
        if (nxt > 0) ba_alt.push(nxt);
    }
    // use odd alternators
    int sub = min(ab, odd_alt);
    ab -= sub; odd_alt -= sub;
    twos_used += sub;
    sub = min(ba, odd_alt);
    ba -= sub; odd_alt -= sub;
    twos_used += sub;
    // use ab on the ba queue
    while (!empty(ba_alt) && ab > 0) {
        int nxt = ba_alt.top() - 1;
        ba_alt.pop();
        int sub = min(ab, nxt);
        ab -= sub; nxt -= sub;
        twos_used += sub;
        if (nxt > 0) ba_alt.push(nxt);
    }
    // use ba on the ab queue
    while (!empty(ab_alt) && ba > 0) {
        int nxt = ab_alt.top() - 1;
        ab_alt.pop();
        int sub = min(ba, nxt);
        ba -= sub; nxt -= sub;
        twos_used += sub;
        if (nxt > 0) ab_alt.push(nxt);
    }
    if (a >= cnt_a - twos_used && b >= cnt_b - twos_used) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
