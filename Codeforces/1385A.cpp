#include <iostream>
using namespace std;

int numSameNums(int a, int b, int c) {
	if ((a == b || b == c || a == c) && not (a == b && b == c)) {
		return 2;
	} else if (a == b && b == c) {
		return 3;
	} else {
		return 0;
	}
}

bool compareTwoNums(int a, int b, int c) {
	int firstNum, secondNum;
	if (a == b) {
		firstNum = a;
		secondNum = c;
	} else if (b == c) {
		firstNum = b;
		secondNum = a;
	} else if (a == c) {
		firstNum = a;
		secondNum = b;
	}
	if (firstNum > secondNum) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int x, y, z, times;
	cin >> times;
	for (int i = 0; i < times; i++) {
		cin >> x >> y >> z;
		if (numSameNums(x, y, z) == 0) {
			cout << "NO\n";
		} else if (numSameNums(x, y, z) == 3) {
			cout << "YES\n" << x << " " << y << " " << z << "\n";
		} else {
			int firstNum, secondNum;
			if (x == y) {
				firstNum = x;
				secondNum = z;
			} else if (y == z) {
				firstNum = y;
				secondNum = x;
			} else if (x == z) {
				firstNum = x;
				secondNum = y;
			}
			if (firstNum > secondNum) {
				cout << "YES\n" << firstNum << " " << secondNum << " " << 1 << "\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
