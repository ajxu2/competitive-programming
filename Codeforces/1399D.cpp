#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    V<int> ans(n);
    // greedily assign subseqs
    array<V<int>, 2> bruh; // bruh[0] = subseqs that end in 0, etc
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        if (bruh[1-num].size() == 0) {
            // create new subseq
            cnt++;
            bruh[num].push_back(cnt);
            ans[i] = cnt;
        } else {
            int tmp = bruh[1-num].back();
            // add this char to the end of that seq
            bruh[1-num].pop_back();
            bruh[num].push_back(tmp);
            ans[i] = tmp;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
