#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure {
public:
    // Виртуальный метод для вычисления геометрического центра
    virtual std::pair<double, double> center() const = 0;

    // Виртуальный метод для вычисления площади
    virtual double area() const = 0;

    // Виртуальный метод для вывода в поток
    virtual void print(std::ostream& os) const = 0;

    // Перегрузка оператора приведения к типу double (площадь)
    virtual operator double() const = 0;

    // Виртуальный деструктор
    virtual ~Figure() = default;

    // Перегрузка оператора << для вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }
};

#endif // FIGURE_H
