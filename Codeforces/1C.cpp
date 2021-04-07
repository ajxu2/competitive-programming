#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;

const long double PI = 3.141592655897932384626433832795;

bool isInteger(long double x) {
    if (abs(round(x) - x) <= 0.001) {
        return true;
    } else {
        return false;
    }
}

long double realacos(long double x) {
    if (x > 1) {
        x = 1;
    } else if (x < -1) {
        x = -1;
    }
    return acos(x);
}

int main() {
    pair<long double, long double> A;
    pair<long double, long double> B;
    pair<long double, long double> C;
    long double a, b, c, s, area, circumradius, cA, cB, cC, sides;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;
    a = sqrt((B.first - C.first)*(B.first - C.first) + (B.second - C.second)*(B.second - C.second));
    b = sqrt((A.first - C.first)*(A.first - C.first) + (A.second - C.second)*(A.second - C.second));
    c = sqrt((A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second));
    // cout << a << " " << b << " " << c << "\n";
    s = (a+b+c)/2.0;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    circumradius = (a*b*c)/(4*area);
    // cout << circumradius << "\n";
    cA = realacos(-1*(a*a - 2*circumradius*circumradius)/(2*circumradius*circumradius));
    cB = realacos(-1*(b*b - 2*circumradius*circumradius)/(2*circumradius*circumradius));
    cC = realacos(-1*(c*c - 2*circumradius*circumradius)/(2*circumradius*circumradius));
    // cout << cA << " " << cB << " " << cC << "\n";
    for (long double i = 3; i <= 100; i++) {
        if (isInteger(cA*i/(2*PI)) && isInteger(cB*i/(2*PI)) && isInteger(cC*i/(2*PI))) {
            sides = i;
            // cout << sides << "\n";
            break;
        }
    }
    cout << fixed << setprecision(6) << sides*(circumradius*circumradius*sin(2*PI/sides)/2) << "\n";
    return 0;
}
