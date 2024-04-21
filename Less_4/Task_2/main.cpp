#include <iostream>

void print_dynamic_array(int *arr, int logical_size, int actual_size) {

    for (int i = 0; i < logical_size; i++) {
        std::cout << arr[i] << " ";
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << "_" << " ";
    }
    std::cout << "\n";
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
        std::cout << "Динамический массив: ";
        return new_array;
    }
}

int *append_to_dynamic_array(int *arr, int &logical_size, int &actual_size, int element) {
    if (logical_size < actual_size) {
        arr[logical_size] = element;
        logical_size++;
        return arr;
    } else {
        int *new_array = new int[actual_size *= 2]{0};
        for (int i = 0; i < logical_size; ++i) {
            new_array[i] = arr[i];
        }
        new_array[logical_size] = element;
        logical_size++;
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
        int element = -1;
        while (element != 0) {
            std::cout << "Введите элемент для добавления: ";
            std::cin >> element;
            if (element != 0) {
                new_array = append_to_dynamic_array(new_array, logical_size, actual_size, element);
                std::cout << "Динамический массив: ";
                print_dynamic_array(new_array, logical_size, actual_size);
            }
        }
        std::cout << "Спасибо! Ваш массив: ";
        print_dynamic_array(new_array, logical_size, actual_size);
    }

    delete[] new_array;
    return 0;
}
