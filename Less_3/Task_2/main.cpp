#include <iostream>

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void quick_sort(int *arr, int size) {
    int i = 0;
    int j = size - 1;
    int middle = arr[size / 2];

    do {
        while (arr[i] < middle)
            i++;
        while (arr[j] > middle)
            j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quick_sort(arr, j + 1);
    }
    if (i < size) {
        quick_sort(&arr[i], size - i);
    }
}

int main() {

    int arr1[]{3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr2[]{88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int arr3[]{24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    std::cout << "Исходный массив: ";
    print_arr(arr1, 10);
    std::cout << "Отсортированный массив: ";
    quick_sort(arr1, 10);
    print_arr(arr1, 10);

    std::cout << "\n";

    std::cout << "Исходный массив: ";
    print_arr(arr2, 15);
    std::cout << "Отсортированный массив: ";
    quick_sort(arr2, 15);
    print_arr(arr2, 15);

    std::cout << "\n";

    std::cout << "Исходный массив: ";
    print_arr(arr3, 18);
    std::cout << "Отсортированный массив: ";
    quick_sort(arr3, 18);
    print_arr(arr3, 18);

    std::cout << "\n";
    return 0;
}
