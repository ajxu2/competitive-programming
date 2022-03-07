// created: 03-06-2022 Sun 09:54 PM

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> blocks(4);
    for (int i = 0; i < 4; i++) cin >> blocks[i];
    sort(blocks.begin(), blocks.end());
    for (int i = 0; i < n; i++) {
        string word; cin >> word;
        string ans = "NO";
        do {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    for (int l = 0; l < 6; l++) {
                        for (int m = 0; m < 6; m++) {
                            string tmp;
                            tmp.push_back(blocks[0][j]);
                            tmp.push_back(blocks[1][k]);
                            tmp.push_back(blocks[2][l]);
                            tmp.push_back(blocks[3][m]);
                            if (tmp.substr(0, word.length()) == word) ans = "YES";
                        }
                    }
                }
            }
        } while (next_permutation(blocks.begin(), blocks.end()));
        cout << ans << "\n";
    }
    return 0;
}
