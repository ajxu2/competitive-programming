// created: 01-01-2026 Thu 07:32 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

using Point = array<ll, 2>;
using IntPoint = array<int, 2>;

Point& operator+=(Point& a, const Point& b) {
    a[0] += b[0];
    a[1] += b[1];
    return a;
}
Point operator+(Point a, Point b) {
    return a += b;
}
Point operator*(ll a, Point b) {
    return {a * b[0], a * b[1]};
}
IntPoint& operator+=(IntPoint& a, const IntPoint& b) {
    a[0] += b[0];
    a[1] += b[1];
    return a;
}
IntPoint operator+(IntPoint a, IntPoint b) {
    return a += b;
}
IntPoint operator*(int a, IntPoint b) {
    return {a * b[0], a * b[1]};
}
Point cast(const IntPoint& a) {
    return {a[0], a[1]};
}
array<IntPoint, 128> mp;
array<char, 128> flip;

enum EventType { ADD, QUERY, REMOVE };

struct Event {
    int x, y1, y2;
    EventType t;
    bool operator<(const Event& o) {
        if (x == o.x) {
            if (t == o.t) {
                return y1 < o.y1;
            }
            return t < o.t;
        }
        return x < o.x;
    }
};

optional<IntPoint> calc_intersection(const V<array<int, 4>>& a) {
    // given horizontal and vertical segments, calculate an intersection point
    V<Event> events;
    for (auto [x1, y1, x2, y2] : a) {
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
        if (x1 == x2) { // vertical
            events.push_back({x1, y1, y2, QUERY});
        } else { // horizontal
            events.push_back({x1, y1, y2, ADD});
            events.push_back({x2, y1, y2, REMOVE});
        }
    }
    sort(begin(events), end(events));
    set<int> active;
    for (int i = 0; i < ssize(events); i++) {
        auto [x, y1, y2, t] = events[i];
        switch (t) {
            case ADD: {
                auto [_, b] = active.insert(y1);
                if (!b) // horizontal segments intersect
                    return IntPoint{x, y1};
                break;
            }
            case QUERY: {
                if (i > 0 && events[i - 1].x == x && events[i - 1].t == QUERY && events[i - 1].y2 >= y1) // vertical segments intersect
                    return IntPoint{x, y1};
                auto it1 = active.lower_bound(y1);
                auto it2 = active.upper_bound(y2);
                if (it1 != it2)
                    return IntPoint{x, *it1};
                break;
            }
            case REMOVE: {
                active.erase(y1);
                break;
            }
        }
    }
    return nullopt;
}

bool on_segment(Point a, Point b, Point c) {
    // return true iff c is on the segment a--b
    Point da = {c[0] - a[0], c[1] - a[1]};
    Point db = {c[0] - b[0], c[1] - b[1]};
    ll cross = da[0] * db[1] - da[1] * db[0];
    ll dot = da[0] * db[0] + da[1] * db[1];
    return cross == 0 && dot <= 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // initialize mp and flip
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    flip['U'] = 'D';
    flip['D'] = 'U';
    flip['L'] = 'R';
    flip['R'] = 'L';
    int n; cin >> n;
    V<pair<char, int>> a(n);
    for (auto& [dir, x] : a)
        cin >> dir >> x;
    // if we ever go some direction and then 180, ignore everything after
    int first_bad_idx = n;
    for (int i = 1; i < n; i++) {
        if (a[i].first == flip[a[i - 1].first]) {
            first_bad_idx = i;
            break;
        }
    }
    a.erase(begin(a) + first_bad_idx, end(a));
    // now, coordinate compress everything
    V<ll> xs(1, 0), ys(1, 0);
    Point cur = {0, 0};
    for (auto [dir, x] : a) {
        cur += x * cast(mp[dir]);
        xs.push_back(cur[0]);
        ys.push_back(cur[1]);
    }
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    auto compress = [&xs, &ys](Point a) -> IntPoint {
        int new_x = lower_bound(begin(xs), end(xs), a[0]) - begin(xs);
        int new_y = lower_bound(begin(ys), end(ys), a[1]) - begin(ys);
        return {new_x, new_y};
    };
    IntPoint compressed_start = compress({0, 0});
    cur = {0, 0};
    IntPoint compressed_cur = compressed_start;
    // modify the directions list to work with the compressed version
    V<pair<char, int>> compressed_a = a;
    for (auto& [dir, x] : compressed_a) {
        cur += x * cast(mp[dir]);
        IntPoint compressed_nxt = compress(cur);
        x = abs(compressed_nxt[0] - compressed_cur[0]) + abs(compressed_nxt[1] - compressed_cur[1]);
        compressed_cur = compressed_nxt;
    }
    ll l = 0, r = 1;
    for (auto [dir, x] : compressed_a)
        r += x;
    auto get_segs = [&](ll steps) -> V<array<int, 4>> {
        IntPoint cur = compressed_start;
        bool first_iter = true;
        V<array<int, 4>> segs;
        for (auto [dir, x] : compressed_a) {
            int walk = min(steps, (ll)x);
            if (walk == 0)
                break;
            IntPoint start = first_iter ? cur : cur + mp[dir];
            IntPoint nxt = cur + walk * mp[dir];
            segs.push_back({start[0], start[1], nxt[0], nxt[1]});
            steps -= walk;
            cur = nxt;
            first_iter = false;
        }
        return segs;
    };
    while (r - l > 1) {
        ll mid = midpoint(l, r - 1);
        // simulate mid steps and find if there is an intersection
        if (calc_intersection(get_segs(mid)))
            r = mid + 1;
        else
            l = mid + 1;
    }
    optional<IntPoint> intersection = calc_intersection(get_segs(l));
    ll ans = 0;
    if (intersection) {
        IntPoint compressed_stop = *intersection;
        Point stop = {xs[compressed_stop[0]], ys[compressed_stop[1]]};
        cur = {0, 0};
        bool encountered = false, first_iter = true;
        for (auto [dir, x] : a) {
            Point start = first_iter ? cur : cur + cast(mp[dir]);
            Point nxt = cur + x * cast(mp[dir]);
            if (on_segment(start, nxt, stop)) {
                if (encountered) {
                    // second time visiting stop, this is the end
                    ans += abs(stop[0] - cur[0]) + abs(stop[1] - cur[1]);
                    break;
                } else {
                    // first time visiting stop
                    encountered = true;
                }
            }
            ans += x;
            cur = nxt;
            first_iter = false;
        }
    } else {
        for (auto [dir, x] : a)
            ans += x;
    }
    cout << ans << '\n';
    return 0;
}
