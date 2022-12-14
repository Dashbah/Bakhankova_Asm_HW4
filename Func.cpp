//
// Created by Dashbah on 14.12.2022.
//
#include <cmath>

extern double left, right;

double EPS = 0.00001;

double Func(double x) {
    return sin(5 * x) + 1;
}

double q_integral(double left_, double right_, double f_left, double f_right, double intgrl_now) {
    double mid = (left_ + right_) / 2;
    double f_mid = Func(mid);

    //Аппроксимация по левому отрезку
    double l_integral = (f_left + f_mid) * (mid - left_) / 2;
    //Аппроксимация по правому отрезку
    double r_integral = (f_mid + f_right) * (right_ - mid) / 2;

    if (abs((l_integral + r_integral) - intgrl_now) > EPS) {
        //Рекурсия для интегрирования обоих значений
        l_integral = q_integral(left_, mid, f_left, f_mid, l_integral);
        r_integral = q_integral(mid, right_, f_mid, f_right, r_integral);
    }

    return (l_integral + r_integral);
}

double getResult() {
    return q_integral(left, right, Func(left), Func(right),
                      (Func(left) + Func(right)) * (right - left) / 2);
}

double checker() {
    return (right - cos(5 * right) / 5) - (left - cos(5 * left) / 5);
}