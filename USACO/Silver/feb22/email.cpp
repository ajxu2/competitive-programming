// created: 03-05-2022 Sat 05:38 PM

#include <bits/stdc++.h>
using namespace std;

// literally copied word for word from Danny Mittal's solution because I am unable to implement stuff myself

vector<int> f;

struct cmp {
    bool operator()(const int& x, const int& y) {
        return f[x] > f[y];
    }
};

void solve() {
    int m, n, k; cin >> m >> n >> k;
    f.clear();
    f.resize(n+1);
    for (int i = 1; i <= n; i++) cin >> f[i];
    vector<int> rem(m+1); // the number of things to file with this folder
    for (int i = 1; i <= n; i++) {
        rem[f[i]]++;
    }
    int topFolder = 1, topEmail = 1, bottomEmail = k;
    vector<bool> filed(n+1, false);
    // pq is a priority queue consisting of the emails on the screen that can be filed
    // the next email we want to file is the one at the front of the pq
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 1; i <= k; i++) pq.push(i);
    while (bottomEmail <= n-1 && topFolder <= m) {
        if (rem[topFolder] == 0) topFolder++; // scroll down folders
        else if (!pq.empty() && f[pq.top()] < topFolder + k) {
            // this email needs to be filed
            int toFile = pq.top();
            pq.pop();
            if (toFile >= topEmail) {
                filed[toFile] = true;
                rem[f[toFile]]--;
                bottomEmail++;
                pq.push(bottomEmail);
            }
        } else {
            // no emails can be filed right now, let's scroll down 
            while (topEmail < n && filed[topEmail]) topEmail++;
            topEmail++;
            bottomEmail++;
            pq.push(bottomEmail);
        }
    }
    string ans = "YES";
    // ok now we need to simulate "scrolling up" behavior
    while (topFolder <= m) {
        if (rem[topFolder] == 0) topFolder++;
        else {
            if (pq.empty()) { // we got here but there were some remaining
                ans = "NO";
                break;
            }
            int toFile = pq.top();
            pq.pop();
            if (toFile >= topEmail && !filed[toFile]) {
                if (f[toFile] >= topFolder + k) {
                    ans = "NO";
                    break;
                }
                filed[toFile] = true;
                rem[f[toFile]]--;
                while (topEmail > 1) {
                    topEmail--;
                    if (!filed[topEmail]) {
                        pq.push(topEmail);
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve(); 
    return 0;
}
