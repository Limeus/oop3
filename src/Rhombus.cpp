#include "../include/Rhombus.h"
#include <iostream>
#include <stdexcept>

// Конструктор с параметрами
Rhombus::Rhombus(const std::pair<double, double>& a, const std::pair<double, double>& b,
                 const std::pair<double, double>& c, const std::pair<double, double>& d)
        : a(a), b(b), c(c), d(d) {}

// Вычисление центра ромба
std::pair<double, double> Rhombus::center() const {
    return {(a.first + b.first + c.first + d.first) / 4,
            (a.second + b.second + c.second + d.second) / 4};
}

// Вычисление площади ромба
double Rhombus::area() const {
    double d1 = std::sqrt(std::pow(a.first - c.first, 2) + std::pow(a.second - c.second, 2));
    double d2 = std::sqrt(std::pow(b.first - d.first, 2) + std::pow(b.second - d.second, 2));
    return (d1 * d2) / 2;
}

// Вывод ромба
void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: A(" << a.first << ", " << a.second << "), B("
       << b.first << ", " << b.second << "), C("
       << c.first << ", " << c.second << "), D("
       << d.first << ", " << d.second << ")";
}

// Приведение к double
Rhombus::operator double() const {
    return area();
}

// Ввод ромба
std::istream& operator>>(std::istream& is, Rhombus& rhombus) {
    is >> rhombus.a.first >> rhombus.a.second
       >> rhombus.b.first >> rhombus.b.second
       >> rhombus.c.first >> rhombus.c.second
       >> rhombus.d.first >> rhombus.d.second;
    return is;
}
