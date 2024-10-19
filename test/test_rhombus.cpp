#include <gtest/gtest.h>
#include "../include/Rhombus.h"  // подключаем файл с реализацией класса
#include <sstream>

TEST(RhombusTest, AreaCalculation) {
    // Пример создания объекта Rhombus с координатами вершин
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Rhombus rhombus(a, b, c, d);

    // Проверяем корректность вычисления площади
    EXPECT_NEAR(static_cast<double>(rhombus), 4.0, 0.1);
}

TEST(RhombusTest, OutputOperator) {
    // Проверка перегрузки оператора вывода
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(1.0, 2.0);
    std::pair<double, double> d(3.0, 2.0);

    Rhombus rhombus(a, b, c, d);
    std::ostringstream oss;
    oss << rhombus;

    // Ожидаем, что вывод будет в нужном формате
    EXPECT_EQ(oss.str(), "Rhombus: A(0, 0), B(2, 0), C(1, 2), D(3, 2)");
}

TEST(RhombusTest, CenterCalculation) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(1.0, 2.0);
    std::pair<double, double> d(3.0, 2.0);

    Rhombus rhombus(a, b, c, d);
    auto center = rhombus.center();

    EXPECT_NEAR(center.first, 1.5, 0.1);
}

// Тесты для операторов копирования и перемещения
TEST(RhombusTest, CopyConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(1.0, 2.0);
    std::pair<double, double> d(3.0, 2.0);

    Rhombus rhombus(a, b, c, d);
    Rhombus rhombusCopy(rhombus);  // Конструктор копирования

    EXPECT_EQ(rhombusCopy, rhombus);  // Проверяем, что они равны
}

TEST(RhombusTest, MoveConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(1.0, 2.0);
    std::pair<double, double> d(3.0, 2.0);

    Rhombus rhombus(a, b, c, d);
    Rhombus rhombusMoved(std::move(rhombus));  // Конструктор перемещения

    EXPECT_NE(rhombusMoved, rhombus);  // Проверяем, что они не равны (первый объект должен быть перемещен)
}
