#include <gtest/gtest.h>
#include "../include/Pentagon.h"  // подключаем файл с реализацией класса
#include <sstream>

TEST(PentagonTest, AreaCalculation) {
    // Пример создания объекта Pentagon с координатами вершин
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 3.0);
    std::pair<double, double> c(4.0, 0.0);
    std::pair<double, double> d(3.0, -2.0);
    std::pair<double, double> e(1.0, -2.0);

    Pentagon pentagon(a, b, c, d, e);

    // Проверяем корректность вычисления площади
    EXPECT_NEAR(static_cast<double>(pentagon), 12.0, 0.1);
}

TEST(PentagonTest, OutputOperator) {
    // Проверка перегрузки оператора вывода
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 3.0);
    std::pair<double, double> c(4.0, 0.0);
    std::pair<double, double> d(3.0, -2.0);
    std::pair<double, double> e(1.0, -2.0);

    Pentagon pentagon(a, b, c, d, e);
    std::ostringstream oss;
    oss << pentagon;

    // Ожидаем, что вывод будет в нужном формате
    EXPECT_EQ(oss.str(), "Pentagon: (0, 0), (2, 3), (4, 0), (3, -2), (1, -2)");
}

TEST(PentagonTest, CenterCalculation) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(1.0, 0.0);
    std::pair<double, double> c(1.5, 1.0);
    std::pair<double, double> d(0.5, 1.0);
    std::pair<double, double> e(0.0, 1.0);

    Pentagon pentagon(a, b, c, d, e);
    auto center = pentagon.center();

    EXPECT_NEAR(center.first, 0.6, 0.1);
}

// Тесты для операторов копирования и перемещения
TEST(PentagonTest, CopyConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 3.0);
    std::pair<double, double> c(4.0, 0.0);
    std::pair<double, double> d(3.0, -2.0);
    std::pair<double, double> e(1.0, -2.0);

    Pentagon pentagon(a, b, c, d, e);
    Pentagon pentagonCopy(pentagon);  // Конструктор копирования

    EXPECT_EQ(pentagonCopy, pentagon);  // Проверяем, что они равны
}

TEST(PentagonTest, MoveConstructor) {
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(2.0, 3.0);
    std::pair<double, double> c(4.0, 0.0);
    std::pair<double, double> d(3.0, -2.0);
    std::pair<double, double> e(1.0, -2.0);

    Pentagon pentagon(a, b, c, d, e);
    Pentagon pentagonMoved(std::move(pentagon));  // Конструктор перемещения

    EXPECT_NE(pentagonMoved, pentagon);  // Проверяем, что они не равны (первый объект должен быть перемещен)
}
