#include <iostream>
#include <cctype>

int main() {
    char array[5][3];

    // Input array elements
    // std::cout << "Enter the 5x3 array of lowercase letters separated by spaces:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> array[i][j];
        }
    }

    // Convert to uppercase
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            array[i][j] = std::toupper(array[i][j]);
        }
    }

    // Output array in uppercase
    // std::cout << "Array in capital letters:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}