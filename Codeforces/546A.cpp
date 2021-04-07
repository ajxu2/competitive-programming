#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n, w, ans;
	cin >> k >> n >> w;
	ans = (k*w*(w+1)/2)-n;
	if (ans > 0) {
		cout << (k*w*(w+1)/2)-n << "\n";
	} else {
		cout << 0 << "\n";
	}
	return 0;
}
