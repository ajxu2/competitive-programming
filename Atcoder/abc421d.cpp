// created: 08-30-2025 Sat 08:13 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

using Point = pair<ll, ll>;
map<char, Point> dir_mp = {{'R', {0, 1}}, {'L', {0, -1}}, {'U', {-1, 0}}, {'D', {1, 0}}};
Point operator+(const Point& a, const Point& b) {
    return {a.first + b.first, a.second + b.second};
}
Point operator-(const Point& a, const Point& b) {
    return {a.first - b.first, a.second - b.second};
}
Point& operator+=(Point& a, const Point& b) {
    return a = a + b;
}
Point operator*(ll a, const Point& b) {
    return {a * b.first, a * b.second};
}
ll dot(const Point& a, const Point& b) {
    return a.first * b.first + a.second * b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll rt, ct, ra, ca; cin >> rt >> ct >> ra >> ca;
    ll n; int m, l; cin >> n >> m >> l;
    V<pair<char, int>> takahashi(m), aoki(l);
    for (auto& [s, a] : takahashi) {
        cin >> s >> a;
    }
    for (auto& [t, b] : aoki) {
        cin >> t >> b;
    }
    Point cur_takahashi = {rt, ct}, cur_aoki = {ra, ca};
    int cur_takahashi_idx = 0, cur_aoki_idx = 0;
    ll ans = 0;
    while (cur_takahashi_idx < m && cur_aoki_idx < l) {
        pair<char, int> ta = takahashi[cur_takahashi_idx];
        pair<char, int> ao = aoki[cur_aoki_idx];
        int dist;
        if (ta.second < ao.second) {
            dist = ta.second;
            cur_takahashi_idx++;
            aoki[cur_aoki_idx].second -= dist;
        } else {
            dist = ao.second;
            cur_aoki_idx++;
            takahashi[cur_takahashi_idx].second -= dist;
            if (takahashi[cur_takahashi_idx].second == 0)
                cur_takahashi_idx++;
        }
        if (cur_takahashi == cur_aoki) {
            if (ta.first == ao.first)
                ans += dist;
        } else if (cur_takahashi.first == cur_aoki.first) {
            if (ta.first == 'R' && ao.first == 'L'
                && cur_takahashi.second < cur_aoki.second
                && (cur_aoki.second - cur_takahashi.second) % 2 == 0
                && (cur_aoki.second - cur_takahashi.second) / 2 <= dist)
                ans++;
            if (ta.first == 'L' && ao.first == 'R'
                && cur_takahashi.second > cur_aoki.second
                && (cur_takahashi.second - cur_aoki.second) % 2 == 0
                && (cur_takahashi.second - cur_aoki.second) / 2 <= dist)
                ans++;
        } else if (cur_takahashi.second == cur_aoki.second) {
            if (ta.first == 'D' && ao.first == 'U'
                && cur_takahashi.first < cur_aoki.first
                && (cur_aoki.first - cur_takahashi.first) % 2 == 0
                && (cur_aoki.first - cur_takahashi.first) / 2 <= dist)
                ans++;
            if (ta.first == 'U' && ao.first == 'D'
                && cur_takahashi.first > cur_aoki.first
                && (cur_takahashi.first - cur_aoki.first) % 2 == 0
                && (cur_takahashi.first - cur_aoki.first) / 2 <= dist)
                ans++;
        } else {
            if (abs(cur_takahashi.first - cur_aoki.first) == abs(cur_takahashi.second - cur_aoki.second)) {
                ll expected_dist = abs(cur_takahashi.first - cur_aoki.first);
                Point int_1 = {cur_takahashi.first, cur_aoki.second};
                Point int_2 = {cur_aoki.first, cur_takahashi.second};
                ll dot_1t = dot(int_1 - cur_takahashi, dir_mp[ta.first]);
                ll dot_1a = dot(int_1 - cur_aoki, dir_mp[ao.first]);
                ll dot_2t = dot(int_2 - cur_takahashi, dir_mp[ta.first]);
                ll dot_2a = dot(int_2 - cur_aoki, dir_mp[ao.first]);
                if (dot_1t > 0 && dot_1a > 0 && expected_dist <= dist)
                    ans++;
                if (dot_2t > 0 && dot_2a > 0 && expected_dist <= dist)
                    ans++;
            }
        }
        cur_takahashi += dist * dir_mp[ta.first];
        cur_aoki += dist * dir_mp[ao.first];
    }
    cout << ans << '\n';
    return 0;
}
