// created: 01-24-2026 Sat 07:07 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    int volume = 0;
    bool playing = false;
    while (q--) {
        int a; cin >> a;
        if (a == 1)
            volume++;
        else if (a == 2)
            volume = max(0, volume - 1);
        else
            playing = !playing;
        cout << (playing && volume >= 3 ? "Yes" : "No") << '\n';
    }
    return 0;
}
