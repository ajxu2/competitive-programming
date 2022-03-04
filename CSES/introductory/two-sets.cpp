// created: 03-03-2022 Fri 2:07 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> ans1, ans2;
    if (n % 4 == 0) {
        for (int i = 1; i <= n; i += 4) {
            ans1.push_back(i);
            ans2.push_back(i+1);
            ans2.push_back(i+2);
            ans1.push_back(i+3);
        }
    } else if (n % 4 == 3) {
        ans1.push_back(1);
        ans1.push_back(2);
        ans2.push_back(3);
        for (int i = 4; i <= n; i += 4) {            
            ans1.push_back(i);
            ans2.push_back(i+1);
            ans2.push_back(i+2);
            ans1.push_back(i+3);
        }
    } else {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n" << ans1.size() << "\n";
    for (int i = 0; i < ans1.size(); i++) cout << ans1[i] << " \n"[i==ans1.size()-1];
    cout << ans2.size() << "\n";
    for (int i = 0; i < ans2.size(); i++) cout << ans2[i] << " \n"[i==ans2.size()-1];
    return 0;
}
