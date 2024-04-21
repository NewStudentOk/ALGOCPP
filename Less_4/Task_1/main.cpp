#include <iostream>

void print_dynamic_array(int *arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << "_" << " ";
    }
}

int *create_dynamic_array(int logical_size, int actual_size) {
    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return nullptr;
    } else {
        int *new_array = new int[actual_size];
        for (int i = 0; i < logical_size; i++) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> new_array[i];
        }
        return new_array;
    }
}

int main() {
    int actual_size = 0;
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;

    int logical_size = 0;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    int *new_array = create_dynamic_array(logical_size, actual_size);
    if (new_array != nullptr) {
        print_dynamic_array(new_array, logical_size, actual_size);
    }

    delete[] new_array;
    return 0;
}
