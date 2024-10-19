#include "../include/Trapezoid.h"
#include <iostream>
#include <stdexcept>

// Конструктор с параметрами
Trapezoid::Trapezoid(const std::pair<double, double>& a, const std::pair<double, double>& b,
                     const std::pair<double, double>& c, const std::pair<double, double>& d)
        : a(a), b(b), c(c), d(d) {}

// Вычисление центра трапеции
std::pair<double, double> Trapezoid::center() const {
    return {(a.first + b.first + c.first + d.first) / 4,
            (a.second + b.second + c.second + d.second) / 4};
}

// Вычисление площади трапеции
double Trapezoid::area() const {
    double area = 0.5 * std::abs(
            a.first * b.second + b.first * c.second + c.first * d.second + d.first * a.second
            - (b.first * a.second + c.first * b.second + d.first * c.second + a.first * d.second)
    );
    return area;
}

// Вывод трапеции
void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: A(" << a.first << ", " << a.second << "), B("
       << b.first << ", " << b.second << "), C("
       << c.first << ", " << c.second << "), D("
       << d.first << ", " << d.second << ")";
}

// Приведение к double
Trapezoid::operator double() const {
    return area();
}

// Ввод трапеции
std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.a.first >> trapezoid.a.second
       >> trapezoid.b.first >> trapezoid.b.second
       >> trapezoid.c.first >> trapezoid.c.second
       >> trapezoid.d.first >> trapezoid.d.second;
    return is;
}
