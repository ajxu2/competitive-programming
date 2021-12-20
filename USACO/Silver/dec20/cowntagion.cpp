// created: 12-19-2021 Sun 09:35 PM

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edgelist;

int betterlog(int a) {
    int b = 0;
    while (a != 1) {
        a /= 2;
        b++;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    edgelist.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        edgelist[a].push_back(b);
        edgelist[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // double up as necessary, then distribute to children nodes
        int tmp = edgelist[i].size();
        if (i == 1) {
            // account for the fact that there's no edge going in
            tmp += 1;
        }
        if (tmp == 1) {
            // no children nodes
            continue;
        }
        ans += (betterlog(tmp-1) + tmp);
    }
    cout << ans << "\n";
    return 0;
}
