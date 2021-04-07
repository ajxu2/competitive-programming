#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    int a, numSwaps = 1, t;
    vector<int> arr;
    getline(cin, s);
    arr.resize((s.size())/2 + 1);
    a = 0;
    for (int i = 0; i < s.size(); i++) {
        if(i%2==0) {
            arr[a] = (int)s[i] - 48;
            ++a;
        }
    }
    while (numSwaps != 0) {
        numSwaps = 0;
        for (int i = 0; i < arr.size()-1; i++) {
            if (arr[i] > arr[i+1]) {
                t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
                ++numSwaps;
            }
        }
    }
    for (int i = 0; i < arr.size()-1; i++) {
        cout << arr[i] << '+';
    }
    cout << arr[arr.size()-1];
    return 0;
}
