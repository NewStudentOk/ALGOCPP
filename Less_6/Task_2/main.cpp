#include <iostream>
#include <cmath>

int real_string_hash(std::string s, int p, int n) {
    long long hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash += s[i] * pow(p,i);
    }
    return hash % n;
}

int main() {
    long long  hash = 0;
    int p, n = 0;
    std::string word;

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    while (word != "exit") {
        std::cout << "Введите строку: ";
        std::cin >> word;
        hash = real_string_hash(word, p, n);
        std::cout << "Хэш строки " << word << " = " << hash << std::endl;
    }

    return 0;
}
