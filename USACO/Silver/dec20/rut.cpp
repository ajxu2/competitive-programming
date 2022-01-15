// created: 01-14-2022 Fri 10:55 PM

#include <bits/stdc++.h>
using namespace std;

struct Cow {
    char dir;
    int x, y, n;
    bool stopped = false;
    Cow* stopper;
};

// copied from bronze solution LOL XDDDDD

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
            if (cows[j].stopped) {
                continue;
            }
            if (cows[i].stopped) {
                break;
            }
            int dx = cows[i].x - cows[j].x;
            int dy = cows[j].y - cows[i].y;
            if (dx > 0 && dy > 0) {
                if (dx > dy) {
                    cows[j].stopped = true;
                    cows[j].stopper = &(cows[i]);
                } else if (dy > dx) {
                    cows[i].stopped = true;
                    cows[i].stopper = &(cows[j]);
                }
            }
        }
    }
    vector<int> blame(n, 0);
    for (int i = 0; i < n; i++) {
        Cow tmp = cows[i];
        while (tmp.stopped) {
            tmp = *(tmp.stopper);
            blame[tmp.n]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << blame[i] << "\n";
    }
    return 0;
}
