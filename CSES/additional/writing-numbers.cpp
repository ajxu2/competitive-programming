// created: 12-25-2025 Thu 09:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

const int DIGITS = 19;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    array<ll, DIGITS> pow10;
    pow10[0] = 1;
    for (int i = 1; i < DIGITS; i++)
        pow10[i] = pow10[i - 1] * 10;
    auto cnt = [&](ll x) -> array<ll, 10> { // digits in 1..x
        array<ll, 10> res;
        res.fill(0);
        for (int i = 0; i < DIGITS; i++) { // count contribution from digit i
            if (x < pow10[i])
                break;
            ll y = x - pow10[i] + 1;
            ll small_blocks = y / pow10[i];
            ll big_blocks = small_blocks / 10;
            for (int j = 0; j < 10; j++)
                res[j] += big_blocks * pow10[i];
            for (int j = 1; j <= small_blocks % 10; j++)
                res[j] += pow10[i];
            int excess_digit = (small_blocks + 1) % 10;
            res[excess_digit] += y % pow10[i];
        }
        return res;
    };
    ll n; cin >> n;
    ll l = 1, r = 1e18;
    while (r - l > 1) {
        ll mid = midpoint(l, r);
        array<ll, 10> res = cnt(mid);
        ll most = *max_element(begin(res), end(res));
        if (most <= n)
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
    return 0;
}
