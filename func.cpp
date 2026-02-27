#include "func.h"

int GetRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

/*
void random_sequence(int n, int *array) {
    int min_r = -50;
    int max_r = 50;
    for (int i = 0; i < n; i++) {
        array[i] = GetRandomNumber(min_r, max_r);
    }
}*/

/*
void random_sequence(int n, int *array) {
    bool alreadyThere;
    int newRandomValue;

    for (int i = 0; i < n;)
    {
        alreadyThere = false;
        newRandomValue = GetRandomNumber(0, n-1);
        for (int j = 0; j < i; j++)
        {
            if (array[j] == newRandomValue)
            {
                alreadyThere = true;
                break;
            }
        }

        if (!alreadyThere)
        {
            array[i] = newRandomValue;
            i++;
        }
    }
}
 */

void ascending_sequence(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void descending_sequence(int n, int *arr) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

int Better_Linear_Search(int *array, int n, int x, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) //Перебираем все элементы массива
    {
        count += 2; //Считаем сравнение в цикле и сравнение с ключом
        if (array[i] == x) //Сравниваем элемент массива с ключом
            return i; //Возвращаем индекс, если совпали
    }
    count++; //Считаем последнее сравнение в цикле, на котором из него вышли
    return -1; //Возвращаем NOT_FOUND
}

int Sentinel_Linear_Search(int *array, int n, int x, int &count) {
    count = 0;
    int last = array[n-1]; //Записываем последний элемент в отдельную переменную last
    array[n-1] = x; //Кладем ключ в последний элемент массива
    int i = 0;
    while (array[i] != x) { //Идем по массиву, пока не
        count++;
        i++;
    }
    count++;
    array[n-1] = last;
    if ((i < n) || (array[n-1] == x)) {
        count++;
        return i;

    }
    return -1;
}

int Ordered_Array_Search(int *array, int n,  int x, int& count) {
    count = 0;
    int i = 0;
    while (i < n && x > array[i]) {
        count++;
        i++;
    }
    if (i < n && x == array[i]) {
        count++;
        return i;
    }
    return -1;
}

int Binary_Search(int *array, int n, int x, int& count) {
    int q;
    int p = 0;
    int r = n - 1;
    while (p <= r)
    {
        q = (p + r) / 2;
        if (array[q] == x) {
            return q;
        }
        else
            if (array[q] > x) {
                r = q - 1;
            }
            else p = q + 1;
    }
    return -1;

}
