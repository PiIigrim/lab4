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
    double y, xa = 0, xb, x0, a = 7, b, sh, y1, x1, rnd, i = 1;
    srand(time(NULL));
    rnd = (-1.0 + static_cast <float> (rand())) / (static_cast <float> (RAND_MAX / (2.0)));
    cout << "Рандомное число: " << rnd << endl;
    cout << "Введите число b(от 2 до 10): ";
    cin >> b;
    while (b > 10 || b < 2) {
        cout << "Написанно ведь: от 2 до 10! Давай еще раз: ";
        cin >> b;
    }
    cout << "Введите начальное значение: ";
    cin >> x0;
    xa = x0;
    cout << "Введите шаг: ";
    cin >> sh;
    do {
        double y = calculation1(xa, a, b);
        double y = calculation2(sh, rnd, xb, y, a, x0, b);
        cout << fixed << "Итерация номер " << i << "\t" << "Значение y: " << y1 << "\t" << "Значение x: " << x0 << "\t" << "Знаечние шага: " << sh << "\t" << endl;
        i++;
    } while (sh > 0.0001);
}