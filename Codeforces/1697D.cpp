// created: 08-02-2022 Tue 03:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

char q1(int i) {
    cout << "? 1 " << i << endl;
    char res; cin >> res;
    if (res == '0') exit(0);
    return res;
}

int q2(int i, int j) {
    cout << "? 2 " << i << " " << j << endl;
    int res; cin >> res;
    if (res == 0) exit(0);
    return res;
}

int main() {
    int n; cin >> n;
    string s = "";
    int prev = 0; // previous # distinct
    vector<pair<int, char>> lst; // (last occurence of char, char)
    for (int i = 1; i <= n; i++) {
        // determine the i-th character
        int dis = q2(1, i);
        if (dis - prev == 1) {
            // this character new
            s.push_back(q1(i));
            lst.push_back({i, s.back()});
        } else {
            // bsearch on last point such that f(x, i) - f(x, i-1) = 0
            // cool thing is we don't even need a query to determine f(x, i-1)!
            int l = 0, r = lst.size() - 1;
            while (l < r) {
                int mid = (l+r+1)/2;
                int res = q2(lst[mid].first, i) - (lst.size() - mid);
                if (res == 0) l = mid;
                else r = mid - 1;
            }
            s.push_back(lst[l].second);
            lst[l].first = i;
        }
        prev = dis;
        sort(lst.begin(), lst.end());
    }
    cout << "! " << s << endl;
    return 0;
}
