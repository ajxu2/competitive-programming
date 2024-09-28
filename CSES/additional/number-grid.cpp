// created: 09-28-2024 Sat 02:32 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

unsigned solve(unsigned x, unsigned y) {
    if (x == 0 && y == 0) return 0;
    unsigned fx = bit_floor(x), fy = bit_floor(y);
    if (fx == fy) return solve(x - fx, y - fy);
    else if (fx < fy) return fy + solve(x, y - fy);
    else return fx + solve(x - fx, y);
    // this is equivalent to x^y :skull:
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    unsigned x, y; cin >> x >> y; x--, y--;
    cout << solve(x, y) << '\n';
    return 0;
}
