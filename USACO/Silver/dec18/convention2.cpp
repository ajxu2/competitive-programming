// created: 12-17-2021 Fri 08:51 PM

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int a, t, s;
    bool operator<(const Cow& b) const { return s < b.s; }
};

int main() {
    ifstream cin("convention2.in");
    ofstream cout("convention2.out");
    int n;
    cin >> n;
    vector<Cow> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].t;
        a[i].s = n - i;
    }
    sort(a.begin(), a.end(), [](const Cow& a, const Cow& b) { return a.a < b.a; });
    priority_queue<Cow> pq;
    int ptr = 1, t = a[0].a, ans = 0;
    pq.push(a[0]);
    while (true) {
        if (pq.empty()) {
            if (ptr == n) break;
            t = a[ptr].a;
            pq.push(a[ptr]);
            ptr++;
        }
        Cow current = pq.top();
        pq.pop();
        ans = max(ans, t - current.a);
        t += current.t;
        if (ptr == n) continue;
        while (a[ptr].a <= t) {
            pq.push(a[ptr]);
            ptr++;
            if (ptr == n) break;
        }
    }
    cout << ans << "\n";
    return 0;
}
