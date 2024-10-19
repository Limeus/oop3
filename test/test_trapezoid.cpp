#include <gtest/gtest.h>
#include "../include/Trapezoid.h"  // подключаем файл с реализацией класса
#include <sstream>

TEST(TrapezoidTest, AreaCalculation) {
    // Пример создания объекта Trapezoid с координатами вершин
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);

    // Проверяем корректность вычисления площади
    EXPECT_NEAR(static_cast<double>(trapezoid), 6.0, 0.1);
}

TEST(TrapezoidTest, OutputOperator) {
    // Проверка перегрузки оператора вывода
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    std::ostringstream oss;
    oss << trapezoid;

    // Ожидаем, что вывод будет в нужном формате
    EXPECT_EQ(oss.str(), "Trapezoid: A(0, 0), B(4, 0), C(3, 2), D(1, 2)");
}

TEST(TrapezoidTest, CenterCalculation) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    auto center = trapezoid.center();

    EXPECT_NEAR(center.first, 2.0, 0.1);
}

// Тесты для операторов копирования и перемещения
TEST(TrapezoidTest, CopyConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    Trapezoid trapezoidCopy(trapezoid);  // Конструктор копирования

    EXPECT_EQ(trapezoidCopy, trapezoid);  // Проверяем, что они равны
}

TEST(TrapezoidTest, MoveConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Trapezoid trapezoid(a, b, c, d);
    Trapezoid trapezoidMoved(std::move(trapezoid));  // Конструктор перемещения

    EXPECT_NE(trapezoidMoved, trapezoid);  // Проверяем, что они не равны (первый объект должен быть перемещен)
}
