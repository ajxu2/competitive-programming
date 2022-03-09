// created: 03-07-2022 Mon 11:09 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, m; cin >> n >> m;
   vector<int> a(n+1);
   for (int i = 0; i < n; i++) {
       int tmp; cin >> tmp;
       a[tmp] = i;
   }
   int ans = 1;
   for (int i = 2; i <= n; i++) {
       if (a[i-1] > a[i]) ans++;
   }
   for (int i = 0; i < m; i++) {
       int x, y; cin >> x >> y;
       swap(a[x], a[y]);
   }
   return 0;
}
