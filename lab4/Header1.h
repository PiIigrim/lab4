#include <iostream>
#include <math.h>
using namespace std;

double calculation2(double sh, double rnd, double xa, double y, double a, double x0, double b) {
    double x1 = x0 + sh * rnd;
    xa = x1;
    double y1 = cos(xa) + (1 / b) * cos(a * xa + 1) + (1 / pow(b, 2)) * cos(pow(a, 2) * xa + 2) + (1 / pow(b, 3)) * cos(pow(a, 3) * xa + 3) + (1 / pow(b, 4)) * cos(pow(a, 4) * xa + 4);
    if (y1 < y) {
        x0 = x1;
        y = y1;
    }
    sh = 0.75 * sh;
    return y1;
};