//10 test cases

#include <iostream>
#include <fstream>
using namespace std;

int m1, m2, m3, c1, c2, c3;

int main()
{
	ifstream fin ("mixmilk.in");
	ofstream fout ("mixmilk.out");
	fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

	for(int i = 1; i <= 33; i++) {
		if(m1 + m2 <= c2) {
			m2 = m1 + m2;
			m1 = 0;
		} else {
			m1 = m1 + m2 - c2;
			m2 = c2;
		}

		if(m2 + m3 <= c3) {
			m3 = m2 + m3;
			m2 = 0;
		} else {
			m2 = m2 + m3 - c3;
			m3 = c3;
		}

		if(m3 + m1 <= c1) {
			m1 = m3 + m1;
			m3 = 0;
		} else {
			m3 = m3 + m1 - c1;
			m1 = c1;
		}
	}

	if(m1 + m2 <= c2) {
		m2 = m1 + m2;
		m1 = 0;
	} else {
		m1 = m1 + m2 - c2;
		m2 = c2;
	}

	fout << m1 << "\n";
	fout << m2 << "\n";
	fout << m3 << "\n";
	return 0;
}
