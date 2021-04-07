#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, a, b;
	cin >> a >> b;
	for (; a <= b; ans++) {
		a *= 3;
		b *= 2;
	}
	cout << ans << "\n";
	return 0;
}
