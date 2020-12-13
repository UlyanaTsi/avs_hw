#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>

// Состояния философов.
const int THINK = 0;
const int HUNGRY = 1;
const int EATING = 2;

const int N = 5;        // Число философов.
int state[N];           // Массив состояний философов.
int left;               // Философ слева.
int right;              // Философ справа.
int eatingTime;         // Время на еду.
int thinkingTime;       // Время на размышления.

sem_t semaphore = 1;    // Блокировка для критических секций.
sem_t sem[N];           // Семафоры каждого из философов.

/**
 * Философ размышляет в течение 1 - 5 секунд.
 * @param i Номер философа.
 */
void think(int i) {
    state[i] = THINK;
    printf("Philosopher %d now thinks about nature of existence\n", i);

    thinkingTime = rand() % 6 + 2;
    sleep(thinkingTime);
}

/**
 * Философ есть в течение 1 - 5 секунд.
 * @param i Номер философа.
 */
void eat(int i) {
    if (state[i] == EATING){
        printf("Philosopher %d took forks and now consumes spaghetti instead of spiritual nourishment\n", i);

        eatingTime = rand() % 6 + 2;
        sleep(eatingTime);
    }
}

/**
 * Проверка свободны ли правая и левая вилка у философа, если да, то он ест.
 * @param i Номер философа.
 */
void checkForks(int i) {
    left = (i + N - 1) % N;
    right = (i + 1) % N;
    if (state[i] == HUNGRY && state[left] != EATING && state[right] != EATING) {
        state[i] = EATING;
        sem_post(&sem[i]);  // Разлокируем философа.
    }
}

/**
 * Процесс взятия вилок философом.
 * @param i Номер философа.
 */
void takeForks(int i) {
    sem_wait(&semaphore);   // Блок секции
    state[i] = HUNGRY;  // Философ хочет есть
    checkForks(i);      // Проверяет наличие вилок
    sem_post(&semaphore);   // Разблок секции

    sem_wait(&sem[i]);  // Если вилок нет, то философ блокируется
}

/**
 * Философ кладет вилки на стол, философы справа и слева могут начать есть, если обе вилки свободны.
 * @param i Номер философа.
 */
void putForks(int i) {
    sem_wait(&semaphore);   // Блок секции
    state[i] = THINK;   // После еды философ размышляет

    // Левый и правый проверяют вилки
    left = (i + N - 1) % N;
    right = (i + 1) % N;
    checkForks(left);
    checkForks(right);

    sem_post(&semaphore);   // Разблок секции
}

/**
 * Представляет собой работу мозга философа за столом.
 * @param i Номер философа.
 */
void *philosopher(void *i_) {
    auto i = (uint64_t) i_;
    while (true) {
        think(i);
        takeForks(i);
        eat(i);
        putForks(i);
    }
}

/**
 * Считывает и проверяет время работы программы введеное пользователем.
 * @return Время в секундах.
 */
int getTime() {
    while (true) {
        std::cout << "\nHow long philosophers are going to have dinner? (20 - 120 seconds)\n";

        int k;
        std::cin >> k;

        if (std::cin.fail() || k < 20 || k > 120) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            return k;
        }
    }
}

/**
 * Инициализация семафоров и создание потоков.
 */
void semaphoreInit() {
    sem_init(&semaphore, 0, 1); // Задаем семафор для блокировок (его начальное значение 1)

    // Задаем семафоры для философов (начальное значение 0)
    for (int i = 0; i < N; ++i) {
        sem_init(&sem[i], 0, 0);
    }

    // Создаем потоки
    pthread_t thread[N];
    for (int i = 0; i < N; ++i){
        pthread_create(&thread[i], nullptr, philosopher, reinterpret_cast<void *>(i));
    }
}

int main() {
    srand(time(0));

    std::cout << "Five philosophers gathered at a round table to reflect and consume pasta.\n"
                 "However they only have 5 forks and need 2 for person to eat spaghetti.\n";

    // Начиаем выполнение работы
    int t = getTime();
    semaphoreInit();

    // Основной поток засыпает на заданное время.
    sleep(t);
    std::cout << "Philosophers finished dinning." << std::endl;

    return 0;
}
