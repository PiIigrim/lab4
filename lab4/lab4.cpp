#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include "Header.h"
#include "Header1.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    double y, xa = 0, x0, a = 7, b, sh, y1 = 1, rnd, i = 1, number1, number2 = 0, result;
    int row, column;
    srand((unsigned)time(NULL));
    double numbers[1000][3];
    rnd = (-1.0 + static_cast <float> (rand())) / (static_cast <float> (RAND_MAX / (2.0)));
    cout << "Рандомное число: " << rnd << endl;
    cout << "Введите число b(от 2 до 10): ";
    cin >> b;
    while (b > 10 || b < 2) {
        cout << "Написанно ведь: от 2 до 10! Давай еще раз: ";
        cin >> b;
    }
    cout << "Введите шаг: ";
    cin >> sh;
    for (row = 0; row < 1000; row++) {
        for (column = 0; column < 3; column++) {
            double x0 = (-10.0 + static_cast <float> (rand())) / (static_cast <float> (RAND_MAX / (30.0)));
            cout << "Начальные значения: " << x0 << endl;
            xa = x0;
            y = calculation1(xa, a, b);
            numbers[row][column] = y;
            do {
                //заменить в отдельный файл
                double x1 = x0 + sh * rnd;
                xa = x1;
                double y1 = cos(xa) + (1 / b) * cos(a * xa + 1) + (1 / pow(b, 2)) * cos(pow(a, 2) * xa + 2) + (1 / pow(b, 3)) * cos(pow(a, 3) * xa + 3) + (1 / pow(b, 4)) * cos(pow(a, 4) * xa + 4);
                if (y1 < y) {
                    x0 = x1;
                    y = y1;
                }
                sh = 0.75 * sh;
                //заменить в отдельный файл
                numbers[row][column] = y1;

            } while (sh > 0.0001);
        }
    }
    cout << "Массив: " << endl;
    cout << "---------------------------------------------" << endl;
    for (row = 0; row < 1000; row++) {
        for (column = 0; column < 3; column++) {
            cout << numbers[row][column] << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------" << endl;
    for (row = 0; row < 1000; row++) {
        for (column = 0; column < 3; column++) {
            number1 = numbers[row][column];
            number2 = number2 + number1;
        }
    }
    result = number2 / (3000);
    cout << "Результат: " << result << endl;
}