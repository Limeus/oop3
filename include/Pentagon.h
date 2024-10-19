#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <utility> // Для std::pair

class Pentagon : public Figure {
private:
    std::pair<double, double> a, b, c, d, e; // Координаты вершин

public:
    // Конструктор по умолчанию
    Pentagon() = default;

    // Конструктор с параметрами
    Pentagon(const std::pair<double, double>& a, const std::pair<double, double>& b,
             const std::pair<double, double>& c, const std::pair<double, double>& d,
             const std::pair<double, double>& e);

    // Копирующий конструктор
    Pentagon(const Pentagon& other)
            : a(other.a), b(other.b), c(other.c), d(other.d), e(other.e) {}

    // Перемещающий конструктор
    Pentagon(Pentagon&& other) noexcept
            : a(std::move(other.a)), b(std::move(other.b)),
              c(std::move(other.c)), d(std::move(other.d)),
              e(std::move(other.e))
    {
        // Устанавливаем перемещаемый объект в корректное состояние
        other.a = {0, 0};
        other.b = {0, 0};
        other.c = {0, 0};
        other.d = {0, 0};
        other.e = {0, 0};
    }

    // Вычисление центра пятиугольника
    std::pair<double, double> center() const override;

    // Вычисление площади пятиугольника
    double area() const override;

    // Вывод пятиугольника
    void print(std::ostream& os) const override;

    // Приведение к double
    operator double() const override;

    // Реализация метода клонирования
    Figure* clone() const override {
        return new Pentagon(*this);
    }

    // Перегрузка оператора сравнения
    bool operator==(const Pentagon& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
    }

    // Перегрузка оператора сравнения
    bool operator==(const Figure& other) const override {
        const Pentagon* o = dynamic_cast<const Pentagon*>(&other);
        return o && *this == *o; // Используем новый оператор == для сравнения
    }

    // Перегрузка оператора неравенства
    bool operator!=(const Figure& other) const {
        return !(*this == other);
    }

    // Ввод пятиугольника
    friend std::istream& operator>>(std::istream& is, Pentagon& pentagon);
};

#endif // PENTAGON_H
