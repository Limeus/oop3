#include <gtest/gtest.h>
#include "../include/Trapezoid.h"  // подключаем файл с реализацией класса
#include <sstream>

TEST(TrapezoidTest, AreaCalculation) {
    // Пример создания объекта Trapezoid с координатами вершин
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);

    // Проверяем корректность вычисления площади
    EXPECT_NEAR(static_cast<double>(trapezoid), 6.0, 0.001);
}

TEST(TrapezoidTest, OutputOperator) {
    // Проверка перегрузки оператора вывода
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    std::ostringstream oss;
    oss << trapezoid;

    // Ожидаем, что вывод будет в нужном формате (например, координаты вершин)
    EXPECT_EQ(oss.str(), "Trapezoid: (0, 0), (3, 0), (4, 2), (1, 2)");
}

TEST(TrapezoidTest, CenterCalculation) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    auto center = trapezoid.center();

    EXPECT_NEAR(center.first, 2.0, 0.001);
    EXPECT_NEAR(center.second, 1.0, 0.001);
}