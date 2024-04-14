#include <iostream>

unsigned long long fib2 (int num){
    long long arr[1000];
    if (arr[num] != 0) { return arr[num]; }
    long long cache = num;
    if (num < 0)
        return 0;
    if (num > 1){
        cache = fib2(num - 1) + fib2(num - 2);

    }
    return arr[num] = cache;
}

int main() {
    unsigned int f;
    std::cout << "Введите число: ";
    std::cin >> f;
    std::cout << "Числа Фибоначчи: " << std::endl;
    for (int num = 0; num <= f; ++num)
        std::cout << num + 1 << ".\t" << "F(" << num << ") = " << fib2(num) << std::endl;
    return 0;
}
