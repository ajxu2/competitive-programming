#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    string thing;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> thing;
        if (thing.size() > 10) {
            cout << thing[0] << thing.size() - 2 << thing[thing.size() - 1] << "\n";
        } else {
            cout << thing << "\n";
        }
    }
    return 0;
}
