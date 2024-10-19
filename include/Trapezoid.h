#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <utility> // Для std::pair

class Trapezoid : public Figure {
private:
    std::pair<double, double> a, b, c, d; // Координаты вершин

public:
    // Конструктор по умолчанию
    Trapezoid() = default;

    // Конструктор с параметрами
    Trapezoid(const std::pair<double, double>& a, const std::pair<double, double>& b,
              const std::pair<double, double>& c, const std::pair<double, double>& d);

    // Копирующий конструктор
    Trapezoid(const Trapezoid& other)
            : a(other.a), b(other.b), c(other.c), d(other.d) {}

    // Перемещающий конструктор
    Trapezoid(Trapezoid&& other) noexcept
            : a(std::move(other.a)), b(std::move(other.b)),
              c(std::move(other.c)), d(std::move(other.d))
    {
        // Устанавливаем перемещаемый объект в корректное состояние
        other.a = {0, 0};
        other.b = {0, 0};
        other.c = {0, 0};
        other.d = {0, 0};
    }

    // Вычисление центра трапеции
    std::pair<double, double> center() const override;

    // Вычисление площади трапеции
    double area() const override;

    // Вывод трапеции
    void print(std::ostream& os) const override;

    // Приведение к double
    operator double() const override;

    // Реализация метода клонирования
    Figure* clone() const override {
        return new Trapezoid(*this);
    }

    // Перегрузка оператора сравнения
    bool operator==(const Trapezoid& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }

    // Перегрузка оператора сравнения
    bool operator==(const Figure& other) const override {
        const Trapezoid* o = dynamic_cast<const Trapezoid*>(&other);
        return o && *this == *o; // Используем новый оператор == для сравнения
    }

    // Перегрузка оператора неравенства
    bool operator!=(const Figure& other) const {
        return !(*this == other);
    }

    // Ввод трапеции
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
};

#endif // TRAPEZOID_H
