#include <iostream>
#include <omp.h>

using namespace std;

// Количество групп пиратов.
int groups;
// Количество участков.
const int DIM = 15;
// Массив, представляющий собой остров, где количество строк - участки,
// а столбцы - места, где могут лежать сокровища.
bool place[DIM][DIM];
// Флаг, сигнализирующий о нахождении клада.
bool flag = false;

// Координаты сокровищ.
int xPos;
int yPos;

// Заполнение массива, в случайную ячейку помещяется true (клад).
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

// Метод поиска по участку
// Если поток не находит на участке клад, то переходт к другому участку.
void search(int cell) {
    if (!flag) {
        bool done = false;
        for (int i = 0; i < DIM; ++i) {
            if (place[cell][i]) {
                flag = true;
                done = true;
                xPos = cell;
                yPos = i;

                cout << "Group of pirates # " << omp_get_thread_num() + 1 << " found treasure at the X: " << xPos << " Y: " << yPos << "\n"
                     << endl;

                exit(0);
            }
        }

        cell = cell + groups;
        // Если клад еще не найден и обследованы не все участки,
        // то пираты переходят к другому участку.
        if (!done && cell < DIM) {
            search(cell);
        }
    }
}

// Считывание количества групп с консоли.
int getNumber() {
    while (true) {
        cout << "Number of groups of pirates in John Silver's gang:" << endl;

        int n;
        cin >> n;

        if (cin.fail() || n < 1 || n > DIM) {
            cin.clear();
            cin.ignore(32767, '\n');
        } else
            return n;
    }
}

int main() {
    srand(time(0));

    cout << "The pirates, led by John Silver, have landed on Treasure Island.\n"
            "Leader of the pirate gang sent groups of pirates to find treasure deep to jungles of island.\n\n";

    groups = getNumber();
    initPlaces();

// Распараллеливает выполнение на потоки.
#pragma omp parallel num_threads(groups)
    {
        auto numb = omp_get_thread_num();
        search(numb);

    }

    return 0;
}
