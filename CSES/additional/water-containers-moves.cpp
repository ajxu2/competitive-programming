// created: 12-23-2025 Tue 02:52 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> using min_pq = priority_queue<T, V<T>, greater<T>>;

enum Move {
    FILL_A,
    FILL_B,
    EMPTY_A,
    EMPTY_B,
    MOVE_AB,
    MOVE_BA
};
using State = pair<int, int>;
string to_string(Move m) {
    switch (m) {
        case FILL_A: return "FILL A";
        case FILL_B: return "FILL B";
        case EMPTY_A: return "EMPTY A";
        case EMPTY_B: return "EMPTY B";
        case MOVE_AB: return "MOVE A B";
        case MOVE_BA: return "MOVE B A";
    }
    return "";
}

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, x; cin >> a >> b >> x;
    if (x > a) {
        cout << "-1\n";
        return 0;
    }
    V<V<int>> dist(a + 1, V<int>(b + 1, INF));
    V<V<pair<State, Move>>> par(a + 1, V<pair<State, Move>>(b + 1));
    min_pq<tuple<int, State, State, Move>> pq; // (dist, new, old, move)
    pq.push({0, {0, 0}, {0, 0}, FILL_A});
    while (!pq.empty()) {
        auto [d, cur_state, old_state, last] = pq.top();
        pq.pop();
        auto [wa, wb] = cur_state;
        if (d >= dist[wa][wb])
            continue;
        dist[wa][wb] = d;
        par[wa][wb] = {old_state, last};
        pq.push({d + a - wa, {a, wb}, cur_state, FILL_A});
        pq.push({d + b - wb, {wa, b}, cur_state, FILL_B});
        pq.push({d + wa, {0, wb}, cur_state, EMPTY_A});
        pq.push({d + wb, {wa, 0}, cur_state, EMPTY_B});
        int tmp = min(wa, b - wb);
        pq.push({d + tmp, {wa - tmp, wb + tmp}, cur_state, MOVE_AB});
        tmp = min(wb, a - wa);
        pq.push({d + tmp, {wa + tmp, wb - tmp}, cur_state, MOVE_BA});
    }
    int best_wb = -1, best_wb_moved = INF;
    for (int i = 0; i <= b; i++) {
        if (dist[x][i] < best_wb_moved) {
            best_wb = i;
            best_wb_moved = dist[x][i];
        }
    }
    if (best_wb == -1) {
        cout << "-1\n";
        return 0;
    }
    V<Move> ans_moves;
    int wa = x, wb = best_wb;
    while (wa > 0 || wb > 0) {
        auto [old_state, move] = par[wa][wb];
        ans_moves.push_back(move);
        tie(wa, wb) = old_state; // wow first time using tie
    }
    reverse(begin(ans_moves), end(ans_moves));
    cout << ssize(ans_moves) << ' ' << best_wb_moved << '\n';
    for (Move move : ans_moves)
        cout << to_string(move) << '\n';
    return 0;
}
