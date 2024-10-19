#include <gtest/gtest.h>
#include "../include/Rhombus.h"  // подключаем файл с реализацией класса
#include <sstream>

TEST(RhombusTest, AreaCalculation) {
    std::pair<double, double> a(0.0, 0.0); // Левый нижний угол
    std::pair<double, double> b(6.0, 0.0); // Правый нижний угол
    std::pair<double, double> c(3.0, 4.0); // Верхний центр
    std::pair<double, double> d(0.0, 4.0); // Левый верхний угол

    Rhombus rhombus(a, b, c, d);

    // Проверяем корректность вычисления площади
    EXPECT_NEAR(static_cast<double>(rhombus), 18.0, 0.1);
}



TEST(RhombusTest, OutputOperator) {
    // Проверка перегрузки оператора вывода
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(4.0, 0.0);
    std::pair<double, double> c(5.0, 3.0);
    std::pair<double, double> d(1.0, 3.0);

    Rhombus rhombus(a, b, c, d);
    std::ostringstream oss;
    oss << rhombus;

    EXPECT_EQ(oss.str(), "Rhombus: (0, 0), (4, 0), (5, 3), (1, 3)");
}

TEST(RhombusTest, CenterCalculation) {
    // Задаем координаты вершин ромба
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 0.0);
    std::pair<double, double> c(3.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    // Создаем экземпляр ромба
    Rhombus rhombus(a, b, c, d);

    // Вычисляем центр
    auto center = rhombus.center();

    // Проверяем, что координаты центра соответствуют ожиданиям
    EXPECT_NEAR(center.first, 1.5, 0.001); // Ожидаемая x-координата
    EXPECT_NEAR(center.second, 1.0, 0.001); // Ожидаемая y-координата
}

