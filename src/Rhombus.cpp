#include "../include/Rhombus.h"
#include <cmath>

// Конструктор с параметрами
Rhombus::Rhombus(const std::pair<double, double>& a, const std::pair<double, double>& b,
                 const std::pair<double, double>& c, const std::pair<double, double>& d)
        : a(a), b(b), c(c), d(d) {}


// Вычисление геометрического центра
std::pair<double, double> Rhombus::center() const {
    double centerX = (a.first + b.first + c.first + d.first) / 4.0;
    double centerY = (a.second + b.second + c.second + d.second) / 4.0;
    return {centerX, centerY};
}

// Вычисление площади ромба
double Rhombus::area() const {
    // Диагональ 1: от a до c
    double d1 = std::sqrt(std::pow(a.first - c.first, 2) + std::pow(a.second - c.second, 2));
    // Диагональ 2: от b до d
    double d2 = std::sqrt(std::pow(b.first - d.first, 2) + std::pow(b.second - d.second, 2));
    return (d1 * d2) / 2.0;  // Площадь ромба
}



// Перегрузка оператора приведения к типу double
Rhombus::operator double() const {
    return area();
}

// Перегрузка оператора для вывода
void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: (" << a.first << ", " << a.second << "), ("
       << b.first << ", " << b.second << "), ("
       << c.first << ", " << c.second << "), ("
       << d.first << ", " << d.second << ")";
}

// Перегрузка оператора >> для ввода
std::istream& operator>>(std::istream& is, Rhombus& rhombus) {
    is >> rhombus.a.first >> rhombus.a.second
       >> rhombus.b.first >> rhombus.b.second
       >> rhombus.c.first >> rhombus.c.second
       >> rhombus.d.first >> rhombus.d.second;
    return is;
}
