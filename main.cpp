#include "func.h"

int main() {
    //Создаем массив указателей на функции
    int (*func[])(int*, int, int, int&) = {Better_Linear_Search, Sentinel_Linear_Search, Ordered_Array_Search, Binary_Search};
    int comparisons_BLS[11][3] = {};
    int comparisons_SLS[11][3] = {};

    for (int i = 10'000; i <= 200'000; i += 19'000)
    {
        cout << "i = " << i << endl;
        int *d_arr1 = new int[i]; //Выделяем память для упорядоченного по убыванию массива на i элементов
        descending_sequence(i, d_arr1); // Заполняем первый массив по убыванию
        int *d_arr2 = new int[i]; //Выделяем память для упорядоченного по возрастанию массива на i элементов
        ascending_sequence(i, d_arr2); // Заполняем первый массив по возрастанию

        int* arrays[] = {d_arr1, d_arr1, d_arr2, d_arr2}; //Массив указателей на массивы для функций

        int N = 5; //Количество измерений времени работы функций

        for (int j = 0; j < 4; j++) //Цикл по массиву указателей на функции
        {
            int count = -1; //Счетчик сравнений.
                        // Для создания массива указателей на функции все функции должны принимать одинаковые аргументы.
                        // В случае если функция не считает количество сравнений, это видно по неизмененному значению счетчика, равному -1
            int sum_time = 0; //Сумма времени выполнения функции, чтобы потом найти среднее арифметическое
            int res; //Переменная, куда записывается результат функции.

            //Находим время работы нахождения ключа в начале
            sum_time = 0; //Обнуляем время
            for (int k = 0; k < N; k++) { //Проводим N измерений времени работы
                auto begin = std::chrono::steady_clock::now(); //Запускаем секундомер
                res = func[j](arrays[j], i, arrays[j][0], count);
                auto end = std::chrono::steady_clock::now(); //Останавливаем секундомер
                auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //Считаем разницу
                sum_time += elapsed_ms.count(); //Прибавляем к суммарному времени
            }
//            cout << sum_time / N << '_'; //Выводим среднее время на экран
            cout << count << '\t'; //Выводим количетство сравнений. Если -1, то функция не считает количество сравнений

            //Находим время работы нахождения ключа в середине
            sum_time = 0; //Обнуляем время
            for (int k = 0; k < N; k++) {
                auto begin = std::chrono::steady_clock::now(); //Запускаем секундомер
                res = func[j](arrays[j], i, arrays[j][i/2], count);
                auto end = std::chrono::steady_clock::now(); //Останавливаем секундомер
                auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //Считаем разницу
                sum_time += elapsed_ms.count(); //Прибавляем к суммарному времени
            }
//            cout << sum_time / N << '_'; //Выводим среднее время на экран
            cout <<  count << '\t'; //Выводим количетство сравнений. Если -1, то функция не считает количество сравнений

            //Находим время работы нахождения ключа в середине
            sum_time = 0; //Обнуляем время
            for (int k = 0; k < N; k++) {
                auto begin = std::chrono::steady_clock::now(); //Запускаем секундомер
                res = func[j](arrays[j], i, arrays[j][i - 1], count);
                auto end = std::chrono::steady_clock::now(); //Останавливаем секундомер
                auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //Считаем разницу
                sum_time += elapsed_ms.count(); //Прибавляем к суммарному времени
            }
//            cout << sum_time / N << '_'; //Выводим среднее время на экран
            cout <<  count << '\t' << endl; //Выводим количетство сравнений. Если -1, то функция не считает количество сравнений

        }
        cout << endl;

        delete[] d_arr1;
        delete[] d_arr2;
    }
}
