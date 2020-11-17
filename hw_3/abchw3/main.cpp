#include <iostream>
#include <thread>
#include <vector>
#include <string>

using namespace std;

// Количество групп пиратов.
const int groups = 5;
// Количество участков.
const int DIM = 15;
// Массив, представляющий собой остров, где количество строк - участки,
// а столбцы - места, где могут лежать сокровища.
bool place[DIM][DIM];
// Флаг, сигнализирующий о нахождении кладе.
bool flag = false;

// Заполнение массива, в случайную ячейку помещяется true (сокровище).
void initPlaces() {
    int dim1 = rand() % 15;
    int dim2 = rand() % 15;

    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            place[i][j] = false;
        }
    }

    place[dim1][dim2] = true;
}

// Поиск клада по cell участку. Выполнякется пока клад не будет найден.
void treasureSearch(int cell, int n) {
    if (!flag) {
        bool done = false;
        for (int i = 0; i < DIM; ++i) {
            if (place[cell][i]) {
                done = true;
                flag = true;
                cout << "Group of pirates # " << n << " found treasure at the " << cell << " place.\n" << endl;
                exit(0);
            }
        }

        cell = cell + groups;
        // Если клад еще не найден и обследованы не все участки,
        // то пираты переходят к другому участку.
        if (!done && cell < DIM) {
            treasureSearch(cell, n);
        }
    }
}

int main() {
    srand(time(0));

    initPlaces();

    cout << "The pirates, led by John Silver, have landed on Treasure Island.\n"
            "Leader of the pirate gang sent groups of pirates to find treasure deep to jungles of island.\n\n";

    // "Портфель" потоков.
    vector<thread> threads;
    threads.reserve(groups);

    // Номер участка.
    int cell = 1;
    // Номер группы пиратов.
    int n = 1;

    // Отправляем пиратов на поиски, пока не найдены сокровища.
    // Каждая группа отправляется на поиски с участка под номером (номер группы - 1) и позже
    // перемешаются по участкам (номер участка + количество групп).
    // Таким образом пираты проходят по всем учаткам.
    for (int i = 0; i < groups; ++i) {
        cout << "Group of pirates # " << n << " start their searches from " << i << " place. \n" << endl;
        threads.emplace_back(treasureSearch, i, n);
        n++;

        if (flag)
            exit(0);
    }

    // Ждем выполнения.
    for (auto &th : threads)
        th.join();
    threads.clear();

    return 0;
}