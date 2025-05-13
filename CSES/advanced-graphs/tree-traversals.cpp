// created: 05-22-2024 Wed 03:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> pre(n), in(n), inmap(n);
    for (int& i : pre) { cin >> i; i--; }
    for (int i = 0; i < n; i++) {
        cin >> in[i]; in[i]--;
        inmap[in[i]] = i;
    }
    V<int> ans;
    auto solve = [&](auto&& self, int pi, int ii, int size) {
        if (size == 0) return;
        int root = pre[pi], rootidx = inmap[root];
        assert(ii <= rootidx && rootidx < ii + size);
        self(self, pi + 1, ii, rootidx - ii);
        self(self, pi + 1 + rootidx - ii, rootidx + 1, size - 1 - rootidx + ii);
        ans.push_back(root);
    };
    solve(solve, 0, 0, n);
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i == n-1];
    return 0;
}
