// created: 05-17-2021 Mon 02:16 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    ifstream cin("rental.in");
    ofstream cout("rental.out");
#endif
    int n, m, r;
    cin >> n >> m >> r;
    vector<long long> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin()+1, a.end(), greater<long long>());
    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
    }
    vector<array<int, 2>> stores(m+1);
    stores[0] = {0, 0};
    for (int i = 1; i <= m; i++) {
        cin >> stores[i][1] >> stores[i][0];
    }
    sort(stores.begin()+1, stores.end(), greater<array<int, 2>>());
    for (int i = 0; i <= m; i++) {
        swap(stores[i][0], stores[i][1]);
    }
    vector<array<long long, 2>> pstores(m+1);
    pstores[0] = {0, 0};
    for (int i = 1; i <= m; i++) {
        pstores[i][0] = pstores[i-1][0] + stores[i][0];
        pstores[i][1] = pstores[i-1][1] + stores[i][0] * stores[i][1];
    }
    vector<long long> rent(r+1, 0);
    for (int i = 1; i <= r; i++) {
        cin >> rent[i];
    }
    sort(rent.begin()+1, rent.end(), greater<long long>());
    for (int i = 1; i <= r; i++) {
        rent[i] += rent[i-1];
    }
    for (int i = 0; i < n-r; i++) {
        rent.push_back(rent.back());
    }
    vector<long long> cowsell(n+1, 0);
    for (int i = 0; i <= n; i++) {
        array<long long, 2> search = {a[i], 0};
        auto ptr = upper_bound(pstores.begin(), pstores.end(), search);
        int j = distance(pstores.begin(), ptr);
        if (j == (int)(pstores.size())) {
            cowsell[i] = pstores.back()[1];
        } else {
            j--;
            cowsell[i] = pstores[j][1];
            int leftover = a[i] - pstores[j][0];
            j++;
            cowsell[i] += leftover * stores[j][1];
        }
    }
    /*
    cout << "COWS:\n";
    for (int i = 0; i <= n; i++) {
        cout << a[i] << "\n";
    }
    cout << "\nSTORES:\n";
    for (int i = 0; i <= m; i++) {
        cout << pstores[i][0] << " " << pstores[i][1] << "\n";
    }
    cout << "\nRENTS:\n";
    for (int i = 0; i <= n; i++) {
        cout << rent[i] << "\n";
    }
    cout << "\nCOWSELL:\n";
    for (int i = 0; i <= n; i++) {
        cout << cowsell[i] << "\n";
    }
    cout << "\n";
    */
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, cowsell[i] + rent[n-i]);
    }
    cout << ans << "\n";
    return 0;
}
