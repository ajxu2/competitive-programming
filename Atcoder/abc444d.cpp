// created: 02-07-2026 Sat 07:04 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int MAXN = 200'100;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a)
        cin >> i;
    V<ll> sfx(MAXN, 0);
    for (int i : a)
        sfx[i]++;
    for (int i = MAXN - 2; i >= 0; i--)
        sfx[i] += sfx[i + 1];
    V<int> ans;
    for (int i = 1; i < MAXN - 1; i++) {
        ans.push_back(sfx[i] % 10);
        sfx[i + 1] += sfx[i] / 10;
    }
    while (ans.back() == 0)
        ans.pop_back();
    reverse(begin(ans), end(ans));
    for (int i : ans)
        cout << i;
    cout << '\n';
    return 0;
}
