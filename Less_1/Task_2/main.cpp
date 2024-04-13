#include <iostream>

int func (int* arr, int size, int stop_point) {
    int left = 0;
    int right = size - 1;
    if (stop_point >= arr[right]) {
        return 0;
    }

    while (left < right) {
        int middle = (left + right) / 2;
        if (arr[middle] > stop_point) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return size - left;
}

int main() {
    int stop_point = 0;
    int size = 9;
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    std::cout << "Введите точку отсчёта: ";
    std::cin >> stop_point;
    std::cout << "Количество элементов в массиве больших, чем " << stop_point << ": " << func(arr,size,stop_point) << std::endl;
    return 0;
}
