#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
private:
    std::pair<double, double> a, b, c, d; // Координаты вершин

public:
    Rhombus() = default;
    Rhombus(const std::pair<double, double>& a, const std::pair<double, double>& b,
            const std::pair<double, double>& c, const std::pair<double, double>& d);


    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    operator double() const override;

    friend std::istream& operator>>(std::istream& is, Rhombus& rhombus);
};

#endif // RHOMBUS_H
