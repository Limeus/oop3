#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"

class Pentagon : public Figure {
private:
    std::pair<double, double> a, b, c, d, e; // Координаты вершин

public:
    Pentagon() = default;
    Pentagon(const std::pair<double, double>& a, const std::pair<double, double>& b,
             const std::pair<double, double>& c, const std::pair<double, double>& d,
             const std::pair<double, double>& e);

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    operator double() const override;

    friend std::istream& operator>>(std::istream& is, Pentagon& pentagon);
};

#endif // PENTAGON_H
