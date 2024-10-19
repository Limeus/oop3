#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <utility> // Для std::pair

class Rhombus : public Figure {
private:
    std::pair<double, double> a, b, c, d; // Координаты вершин

public:
    // Конструктор по умолчанию
    Rhombus() = default;

    // Конструктор с параметрами
    Rhombus(const std::pair<double, double>& a, const std::pair<double, double>& b,
            const std::pair<double, double>& c, const std::pair<double, double>& d);

    // Копирующий конструктор
    Rhombus(const Rhombus& other)
            : a(other.a), b(other.b), c(other.c), d(other.d) {}

    // Перемещающий конструктор
    Rhombus(Rhombus&& other) noexcept
            : a(std::move(other.a)), b(std::move(other.b)),
              c(std::move(other.c)), d(std::move(other.d))
    {
        // Устанавливаем перемещаемый объект в корректное состояние
        other.a = {0, 0};
        other.b = {0, 0};
        other.c = {0, 0};
        other.d = {0, 0};
    }

    // Вычисление центра ромба
    std::pair<double, double> center() const override;

    // Вычисление площади ромба
    double area() const override;

    // Вывод ромба
    void print(std::ostream& os) const override;

    // Приведение к double
    operator double() const override;

    // Реализация метода клонирования
    Figure* clone() const override {
        return new Rhombus(*this);
    }

    // Перегрузка оператора сравнения
    bool operator==(const Rhombus& other) const {
        return a == other.a && b == other.b && c == other.c && d == other.d;
    }

    // Перегрузка оператора сравнения
    bool operator==(const Figure& other) const override {
        const Rhombus* o = dynamic_cast<const Rhombus*>(&other);
        return o && *this == *o; // Используем новый оператор == для сравнения
    }

    // Перегрузка оператора неравенства
    bool operator!=(const Figure& other) const {
        return !(*this == other);
    }

    // Ввод ромба
    friend std::istream& operator>>(std::istream& is, Rhombus& rhombus);
};

#endif // RHOMBUS_H

