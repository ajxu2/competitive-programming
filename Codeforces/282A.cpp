#include <iostream>
#include <string>

int main() {
    int x = 0, t;
    std::string s;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> s;
        if (s[1] == '+') {
            ++x;
        } else {
            --x;
        }
    }
    std::cout << x;
    return 0;
}
