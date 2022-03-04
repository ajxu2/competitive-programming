// created: 03-03-2022 Fri 3:07 PM
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<string> ans;
    string tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back('0');
    }
    ans.push_back(tmp);
    for (int i = 0; i < n; i++) {
        // double this n times
        for (int j = ans.size()-1; j >= 0; j--) {
            string tmp = ans[j];
            tmp[n-i-1] = '1';
            ans.push_back(tmp);
        }
    }
    for (string i : ans) cout << i << "\n";
    return 0;
}
