#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(7);
    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << nums[0] << " " << nums[1] << " " << nums[6]-nums[0]-nums[1] << "\n";
    return 0;
}
