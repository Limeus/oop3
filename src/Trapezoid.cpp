#include "../include/Trapezoid.h"
#include <cmath>


// Конструктор с параметрами
Trapezoid::Trapezoid(const std::pair<double, double>& a, const std::pair<double, double>& b,
                     const std::pair<double, double>& c, const std::pair<double, double>& d)
        : a(a), b(b), c(c), d(d) {}


// Вычисление геометрического центра
std::pair<double, double> Trapezoid::center() const {
    double centerX = (a.first + b.first + c.first + d.first) / 4.0;
    double centerY = (a.second + b.second + c.second + d.second) / 4.0;
    return {centerX, centerY};
}

// Вычисление площади трапеции по формуле площади (пример, основанный на координатах вершин)
double Trapezoid::area() const {
    double area = 0.5 * std::abs(
            a.first * b.second + b.first * c.second + c.first * d.second + d.first * a.second
            - (b.first * a.second + c.first * b.second + d.first * c.second + a.first * d.second)
    );
    return area;
}

// Перегрузка оператора приведения к типу double
Trapezoid::operator double() const {
    return area();
}

// Перегрузка оператора для вывода
void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: (" << a.first << ", " << a.second << "), ("
       << b.first << ", " << b.second << "), ("
       << c.first << ", " << c.second << "), ("
       << d.first << ", " << d.second << ")";
}

// Перегрузка оператора >> для ввода
std::istream& operator>>(std::istream& is, Trapezoid& trap) {
    is >> trap.a.first >> trap.a.second
       >> trap.b.first >> trap.b.second
       >> trap.c.first >> trap.c.second
       >> trap.d.first >> trap.d.second;
    return is;
}
