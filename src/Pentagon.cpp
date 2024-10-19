#include "../include/Pentagon.h"
#include <cmath>

// Конструктор с параметрами
Pentagon::Pentagon(const std::pair<double, double>& a, const std::pair<double, double>& b,
                   const std::pair<double, double>& c, const std::pair<double, double>& d,
                   const std::pair<double, double>& e)
        : a(a), b(b), c(c), d(d), e(e) {}

// Вычисление центра пятиугольника
std::pair<double, double> Pentagon::center() const {
    double x_center = (a.first + b.first + c.first + d.first + e.first) / 5.0;
    double y_center = (a.second + b.second + c.second + d.second + e.second) / 5.0;
    return {x_center, y_center};
}


// Вычисление площади пятиугольника (разбиваем на треугольники)
double Pentagon::area() const {
    // Площадь через формулу площади многоугольника
    double area = 0.5 * std::abs(
            a.first * b.second + b.first * c.second + c.first * d.second + d.first * e.second + e.first * a.second
            - (b.first * a.second + c.first * b.second + d.first * c.second + e.first * d.second + a.first * e.second)
    );
    return area;
}

// Приведение к double
Pentagon::operator double() const {
    return area();
}

// Вывод пятиугольника
void Pentagon::print(std::ostream& os) const {
    os << "Pentagon: (" << a.first << ", " << a.second << "), ("
       << b.first << ", " << b.second << "), ("
       << c.first << ", " << c.second << "), ("
       << d.first << ", " << d.second << "), ("
       << e.first << ", " << e.second << ")";
}

// Ввод пятиугольника
std::istream& operator>>(std::istream& is, Pentagon& pentagon) {
    is >> pentagon.a.first >> pentagon.a.second
       >> pentagon.b.first >> pentagon.b.second
       >> pentagon.c.first >> pentagon.c.second
       >> pentagon.d.first >> pentagon.d.second
       >> pentagon.e.first >> pentagon.e.second;
    return is;
}
