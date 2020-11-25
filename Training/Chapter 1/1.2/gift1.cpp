/*
ID: tony.ji1
LANG: C++14
PROG: gift1
*/

#include <bits/stdc++.h>
using namespace std;

const string filename = "gift1";

int main() {
#ifndef LOCAL
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
#endif
    int np;
    cin >> np;
    map<string, int> data;
    vector<string> order;
    string temp;
    for (int i = 0; i < np; i++) {
        cin >> temp;
        order.push_back(temp);
        data[temp] = 0;
    }
    string name, recipient;
    int money, numRecipients;
    for (int i = 0; i < np; i++) {
        cin >> name >> money >> numRecipients;
        data[name] -= money;
        if (numRecipients != 0) {
            data[name] += (money % numRecipients);
            for (int j = 0; j < numRecipients; j++) {
                cin >> recipient;
                data[recipient] += (money / numRecipients);
            }
        }
    }
    for (int i = 0; i < np; i++) {
        cout << order[i] << " " << data[order[i]] << "\n";
    }
    return 0;
}

