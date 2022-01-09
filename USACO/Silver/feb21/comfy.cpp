// created: 01-02-2022 Sun 09:44 PM

#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    // array of cows
    array<array<bool, 3001>, 3001> a;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        queue<array<int, 2>> q;
        int x, y;
        cin >> x >> y;
        // add 1000 to make them non-negative
        x += 1000; y += 1000;
        q.push({x, y});
        // fancy lambda expression to figure out cows to push
        // let's be honest I'm literally copying the editorial here
        auto addcows = [&](int x1, int y1) {
            if (!a[x1][y1]) return;
            // get number of neighbors
            int neighbors = 0;
            for (int j = 0; j < 4; j++) {
                if (a[x1+dx[j]][y1+dy[j]]) neighbors++;
            }
            if (neighbors == 3) {
                for (int j = 0; j < 4; j++) {
                    if (!a[x1+dx[j]][y1+dy[j]]) {
                        q.push({x1+dx[j], y1+dy[j]});
                        return;
                    }
                }
            }
        };
        // run ff
        while (!q.empty()) {
            array<int, 2> process = q.front();
            q.pop();
            int x1 = process[0], y1 = process[1];
            if (a[x1][y1]) continue;
            a[x1][y1] = true;
            total++;
            addcows(x1, y1);
            for (int j = 0; j < 4; j++) {
                addcows(x1+dx[j], y1+dy[j]);
            }
        }
        cout << total - i << "\n";
    }
    return 0;
}
