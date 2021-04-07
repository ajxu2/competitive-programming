#include <iostream>
#include <vector>
using namespace std;

bool inTable(long long n, int x, int y) {
	for (int i = 1; i <= n && i <= x; i++) {
		if (n%i == 0 && n/i <= y) {
			return true;
		}
	}
	return false;
}

long long numrank(long long n, long long x, long long y) {
	long long value = 0;
	for (int i = 1; i <= x; i++) {
		if (n >= i*y) {
			value += y;
		} else {
			value += (n/i);
		}
	}
	return value;
}

int main() {
	long long k, ans, lb, ub, mid, n, m;
	cin >> n >> m >> k;
	lb = 0;
	ub = n*m;
	while (ub - lb != 1) {
		mid = (lb+ub)/2;
		if (numrank(mid, n, m) > k) {
			ub = mid;
		} else if (numrank(mid, n, m) < k) {
			lb = mid;
		} else {
			lb = mid - 1;
			ub = mid;
		}
	}
	ans = ub;
	while (!inTable(ans, n, m)) {
		ans--;
	}
	cout << ans << "\n";
	return 0;
}
