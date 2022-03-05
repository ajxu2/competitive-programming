// created: 02-25-2022 Fri 10:24 PM

#include <bits/stdc++.h>
using namespace std;

// i literally hate my life i spent like 6 hours implementing this piece of flaming garbage
// ...at least it got AC!!!!!

struct Edge {
    int to, from, n;
    bool thisWay;
    Edge(int _from, int _to, int _n, bool _thisWay) {
        from = _from; to = _to; n = _n; thisWay = _thisWay;
    }
    bool operator<(const Edge& y) const {
        if (n == y.n) return from < y.from;
        return n < y.n;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<Edge>> adj(m+1);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(Edge(a, b, i+1, true));
        adj[b].push_back(Edge(b, a, i+1, false));
    }
    vector<bool> visited(m+1, false);
    // for the spanning trees
    vector<vector<Edge>> adj2(m+1);
    vector<bool> visited2(m+1, false);
    vector<int> totalAns;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (visited[i]) continue;
        vector<int> thisAns;
        vector<int> listNodes;
        // find a spanning tree of this CC
        queue<int> q;
        set<Edge> extra, st;
        q.push(i); visited[i] = true; listNodes.push_back(i);
        while (!q.empty()) {
            int process = q.front();
            q.pop();
            for (Edge j : adj[process]) {
                extra.insert(j);
                if (!visited[j.to]) {
                    q.push(j.to); visited[j.to] = true; listNodes.push_back(j.to);
                    adj2[process].push_back(j);
                    adj2[j.to].push_back(Edge(j.to, j.from, j.n, !j.thisWay));
                    st.insert(j);
                    st.insert(Edge(j.to, j.from, j.n, !j.thisWay));
                }
            }
        }
        for (Edge j : st) extra.erase(j);
        // divide by 2 because edges double counted
        int numExtra = extra.size() / 2;
        ans += max(0, numExtra - 1);
        if (numExtra == 0) {
            // run BFS on the spanning tree
            q.push(i); visited2[i] = true;
            while (!q.empty()) {
                int process = q.front();
                q.pop();
                for (Edge j : adj2[process]) {
                    if (!visited2[j.to]) {
                        totalAns.push_back(j.n);
                        q.push(j.to); visited2[j.to] = true;
                    }
                }
            }
        } else {
            // get one edge
            Edge oneExtra = *(extra.begin());
            totalAns.push_back(oneExtra.n);
            // root the spanning tree at the corresponding node
            if (oneExtra.thisWay) {
                q.push(oneExtra.from); visited2[oneExtra.from] = true;
            } else {
                q.push(oneExtra.to); visited2[oneExtra.to] = true;
            }
            while (!q.empty()) {
                int process = q.front();
                q.pop();
                for (Edge j : adj2[process]) {
                    if (!visited2[j.to]) {
                        totalAns.push_back(j.n);
                        q.push(j.to); visited2[j.to] = true;
                    }
                }
            }
            auto it = next(extra.begin(), 2);
            while (it != extra.end() && it != extra.end()++) {
                totalAns.push_back(it->n);
                it = next(it, 2);
            }
        }
    }
    cout << ans << "\n";
    for (int i : totalAns) cout << i << "\n";
    return 0;
}
