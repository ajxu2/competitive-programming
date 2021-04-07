#include <bits/stdc++.h>
using namespace std;

int main() {
	int coins, ans = 0, sum = 0, ptr, realans = 0;
	vector<int> values;
	cin >> coins;
	values.resize(coins);
	for (int i = 0; i < coins; i++) {
		cin >> values[i];
		sum += values[i];
	}
	sort(values.begin(), values.end());
	ptr = coins - 1;
	while (ans <= (sum/2)) {
		ans += values[ptr];
		ptr--;
		realans++;
	}
	cout << realans << "\n";
	return 0;
}
