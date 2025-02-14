#include <iostream>

int main() {
    long int largeValue = 2415919104; // 2^31, which is out of range for a 32-bit int
    int intValue = static_cast<int>(largeValue);

    std::cout << "Original long int value: " << largeValue << std::endl;
    std::cout << "Converted int value: " << intValue << std::endl;

    std::cout << "Max value of int: " << INT_MAX << std::endl;
    std::cout << "Min value of int: " << INT_MIN << std::endl;
    std::cout << "Max value of long int: " << LONG_MAX << std::endl;
    std::cout << "Min value of long int: " << LONG_MIN << std::endl;
    return 0;
}