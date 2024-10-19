#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"

class Trapezoid : public Figure {
private:
    std::pair<double, double> a, b, c, d; // Координаты вершин

public:
    Trapezoid() = default;
    Trapezoid(const std::pair<double, double>& a, const std::pair<double, double>& b,
              const std::pair<double, double>& c, const std::pair<double, double>& d);


    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    operator double() const override;

    friend std::istream& operator>>(std::istream& is, Trapezoid& trap);
};

#endif // TRAPEZOID_H
