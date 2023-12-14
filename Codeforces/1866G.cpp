// created: 12-08-2023 Fri 10:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct Segment {
    int l, r, n;
    Segment(int l, int r, int n) : l(l), r(r), n(n) {}
    Segment() {}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n), d(n);
    for (int& i : a) cin >> i;
    for (int& i : d) cin >> i;
    V<Segment> segs(n); // lol
    for (int i = 0; i < n; i++) segs[i] = Segment(max(0, i - d[i]), min(n-1, i + d[i]), a[i]);
    V<V<Segment>> whar(n, V<Segment>());
    for (Segment i : segs) whar[i.l].push_back(i);
    // find first true s.t. all elements can <= Z
    auto check = [&](int x) {
        auto cmp = [](const Segment& i, const Segment& j) { return i.r > j.r; };
        priority_queue<Segment, vector<Segment>, decltype(cmp)> pq;
        for (int i = 0; i < n; i++) {
            for (Segment j : whar[i]) pq.push(j);
            if (!empty(pq) && pq.top().r < i) return false;
            int tmp = 0;
            while (!empty(pq) && tmp + pq.top().n <= x) {
                tmp += pq.top().n;
                pq.pop();
            }
            if (!empty(pq)) {
                Segment tmp2 = pq.top();
                pq.pop();
                tmp2.n -= x - tmp;
                pq.push(tmp2);
            }
        }
        if (!empty(pq)) return false;
        return true;
    };
    int l = 0, r = 2e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}
