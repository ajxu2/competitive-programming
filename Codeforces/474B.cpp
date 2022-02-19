#include <iostream>
#include <vector>

int main() {
    int numberOfPiles = 0, numberOfJuicyWorms = 0, numberToAdd = 0, index = 0;
    std::cin >> numberOfPiles;
    std::vector<int> lookupTable;
    lookupTable.push_back(0);
    for (int i = 1; i <= numberOfPiles; i++) {
        std::cin >> numberToAdd;
        for (int j = 0; j < numberToAdd; j++) {
            lookupTable.push_back(i);
        }
    }
    std::cin >> numberOfJuicyWorms;
    for (int i = 0; i < numberOfJuicyWorms; i++) {
        std::cin >> index;
        std::cout << lookupTable[index] << "\n";
    }
    return 0;
}
