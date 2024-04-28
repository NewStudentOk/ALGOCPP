#include <iostream>
#include <cmath>
#include <cstring>

void print_array(int* arr, int size) {
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}
int get_level(int i) {
    return ilogb(i + 1);
}
bool get_left_index(int& index, int i, int size) {
    index = 2 * i + 1;
    if (index >= size) {return false;}
    else return true;
}
bool get_right_index(int& index, int i, int size) {
    index = 2 * i + 2;
    if (index >= size){return false;}
    else return true;
}
void get_parent_index(int& index, int i) {
    index = (i - 1) / 2;
}
void print_pyramid(int* arr, int size) {
    std::cout << "Пирамида: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::string position;
        if (i == 0) {
            std::cout << 0 << " root " << arr[i] << std::endl;
        }
        else {
            if (i % 2 == 0 && i != 0) position = "right";
            if (i % 2 != 0 && i != 0) position = "left";
            std::cout << get_level(i) << " " << position << "(" << arr[(i - 1) / 2] << ")" << " " << arr[i] << std::endl;
        }
    }
}
void print_element(int* arr, int i) {
    std::string position;
    if (i == 0) {
        std::cout << 0 << " root " << arr[i] << std::endl;
    }
    else {
        if (i % 2 == 0 && i != 0) position = "right";
        if (i % 2 != 0 && i != 0) position = "left";
        std::cout << get_level(i) << " " << position << "(" << arr[(i - 1) / 2] << ")" << " " << arr[i] << std::endl;
    }
}

int main() {
    int x = 0;
    int size = 0;
    std::string command;
    int arr[10] = {};
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };


    std::cout << "Введите число от 1 до 3 для выбора массива: ";
    std::cin >> x;

    if (x == 1) { memcpy(arr, arr1, sizeof arr1);
        size = sizeof(arr1) / sizeof(arr1[0]);}
    if (x == 2) {memcpy(arr, arr2, sizeof arr2);
        size= sizeof(arr2) / sizeof(arr2[0]);}
    if (x == 3) {
        memcpy(arr, arr3, sizeof arr3);
        size= sizeof(arr3) / sizeof(arr3[0]);}

    print_array(arr, size);
    print_pyramid(arr, size);

    int i = 0;
    int j = 0;

    std::cout << "Для перемещения по пирамиде вводите команды: \n" << "right \n"  << "left \n"  << "up \n"  << "Для выхода введите: exit"  << std::endl;

    do {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, j);
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "up") {
            if (i == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                j = i;
            }
            else {
                get_parent_index(j, i);
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (command == "left") {
            if (get_left_index(j, i, size) == false) {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
                j = i;
            }
            else {
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (command == "right") {
            if (get_right_index(j, i, size) == false) {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
                j = i;
            }
            else {
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (command == "exit") break;
        else std::cout << "Ошибка! Неверная команда" << std::endl;

    } while (command != "exit");

    return 0;
}
