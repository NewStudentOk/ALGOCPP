#include <iostream>

int simple_string_hash(std::string s) {
    int hash = 0;
    for (int i = 0; i < s.length(); i++) {
        hash += s[i];
    }
    return hash;
}

int main() {
    int hash = 0;
    std::string word;
    while (word != "exit") {
        std::cout << "Введите строку: ";
        std::cin >> word;
        hash = simple_string_hash(word);
        std::cout << "Наивный хэш строки " << word << " = " << hash << std::endl;
    }

    return 0;
}
