#include <iostream>

int fib (int num){
    if (num == 1 || num == 2)
        return 1;
    if (num == 0)
        return 0;
    return fib(num - 1) + fib (num - 2);
}

int main() {
    int f;
    std::cout << "Введите число: ";
    std::cin >> f;
    std::cout << "Числа Фибоначчи: " << std::endl;
    for (int num = 0; num < f; ++num)
        std::cout << num << ": " << fib(num) << std::endl;
    return 0;
}
/* сложность:
 по скорости - О(2^n)
 по памяти - O(1)
*/