#include <iostream>
#include <fstream>
#include <list>

int **create_double_array(int n) {
    int **arr = new int *[n]();
    for (int i = 0; i < n; i++) arr[i] = new int[n]();
    return arr;
}

void delete_double_array(int **arr, int n) {
    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
}

void print_adjacency_matrix(int **arr, int n) {
    std::cout << "Матрица смежности графа: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void print_list(std::list<int> &list) {
    for (auto &i : list) {
        std::cout << " " << i;
    }
}

void dfs(int **graph, bool *visited, std::list<int> &order, int v, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < v; i++) {
        if ((graph[vertex][i] != 0) && (!visited[i])) {
            dfs(graph, visited, order, v, i);
        }
    }
    order.insert(order.begin(), vertex + 1);
}

void top_sort(int **graph, int v, int vertex) {
    std::cout << "Топологический порядок вершин:";
    std::list<int> order;
    bool *visited = new bool[v]{};
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            dfs(graph, visited, order, v, i);
        }
    }

    print_list(order);
}

int main(int argc, char **argv) {

    int v;
    int num;
    std::string text[2] = {"input1.txt", "input2.txt"};
    std::string message[2] = {"1 - Пример 1\n", "2 - Пример 2\n"};
    std::cout << "Выберете какой пример вам нужен?" << std::endl;
    for (int i = 1; i <= 2; i++)
        std::cout << message[i - 1];
    std::cout << "Ваш выбор: ";
    std::cin >> num;

    if (num > 2 || num < 1) {
        std::cout << "Введено неправильное значение!" << std::endl;
        std::cout << "Автоматически выбран Пример 1" << std::endl;
        num = 1;
    }

    std::string fname = text[num - 1];
    std::ifstream fin(fname);


    if (fin.is_open()) {
        fin >> v;
        int **graph = create_double_array(v);
        bool *visited = new bool[v]();

        while (!fin.eof()) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    fin >> graph[i][j];
                }
            }
        }
        print_adjacency_matrix(graph, v);
        std::cout << std::endl;
        top_sort(graph, v, 0);
        std::cout << std::endl;

        fin.close();
        delete_double_array(graph, v);
        delete[] visited;
    } else std::cout << "Файл не открывается!" << std::endl;

    return 0;
}