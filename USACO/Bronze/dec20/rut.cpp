#include <bits/stdc++.h>
using namespace std;

struct Cow {
    char dir;
    int x, y, ts = -1, n;
};

bool cmp(const Cow& a, const Cow& b) {
    if (a.dir != b.dir) {
        return a.dir > b.dir;
    } else {
        if (a.dir == 'N') {
            return a.x < b.x;
        } else {
            return a.y < b.y;
        }
    }
}

bool cmp1(const Cow& a, const Cow& b) {
    return a.n < b.n;
}

int main() {
    int n;
    cin >> n;
    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
        cows[i].n = i;
    }
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (cows[i].dir == 'E') {
            break;
        }
        for (int j = i; j < n; j++) {
            if (cows[j].dir == 'N') {
                continue;
            }
            if (cows[j].ts != -1) {
                continue;
            }
            if (cows[i].ts != -1) {
                break;
            }
            int dx = cows[i].x - cows[j].x;
            int dy = cows[j].y - cows[i].y;
            if (dx > 0 && dy > 0) {
                if (dx > dy) {
                    cows[j].ts = dx;
                } else if (dy > dx) {
                    cows[i].ts = dy;
                }
            }
        }
    }
    sort(cows.begin(), cows.end(), cmp1);
    for (int i = 0; i < n; i++) {
        if (cows[i].ts == -1) {
            cout << "Infinity\n";
        } else {
            cout << cows[i].ts << "\n";
        }
    }
    return 0;
}
