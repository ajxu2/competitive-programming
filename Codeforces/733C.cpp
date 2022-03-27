// created: 03-15-2022 Tue 09:03 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    int k; cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];
    bool works = true;
    int sum = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    for (int i = 0; i < k; i++) sum -= b[i];
    if (sum != 0) {
        cout << "NO\n";
        return 0;
    }
    vector<array<int, 2>> ans;
    for (int i = 0; i < k; i++) {
        sum = 0; l = r;
        while (r < n && sum + a[r] <= b[i]) {
            sum += a[r];
            r++;
        }
        if (sum != b[i]) {
            works = false;
            break;
        }
        int indexMax = l;
        bool allsame = true, startingR = false;
        for (int j = l; j < r-1; j++) {
            if (a[j] != a[j+1]) allsame = false;
            if (a[j+1] > a[indexMax]) indexMax = j+1;
        }
        if (allsame && r - l > 1) {
            works = false;
            break;
        }
        if (indexMax == l) {
            startingR = true;
            while (indexMax < r-1 && a[indexMax] == a[indexMax+1]) indexMax++;
        }
        if (startingR) {
            for (int j = indexMax+1; j <= r-1; j++) ans.push_back({indexMax-l+i+1, 1});
            for (int j = indexMax-l+i+1; j >= i+2; j--) ans.push_back({j, -1});
        } else {
            for (int j = indexMax-l+i+1; j >= i+2; j--) ans.push_back({j, -1});
            for (int j = indexMax+1; j <= r-1; j++) ans.push_back({i+1, 1});
        }
    }
    if (works) {
        cout << "YES\n";
        for (array<int, 2> i : ans) {
            cout << i[0] << " ";
            if (i[1] == -1) cout << "L\n";
            else cout << "R\n";
        }
    } else cout << "NO\n";
    return 0;
}
