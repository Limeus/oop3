#include <gtest/gtest.h>
#include "../include/Array.h"  // Подключаем файл с реализацией класса FigureArray
#include "../include/Trapezoid.h"  // Подключаем файл с реализацией класса Trapezoid
#include "../include/Rhombus.h"  // Подключаем файл с реализацией класса Rhombus
#include "../include/Pentagon.h"  // Подключаем файл с реализацией класса Pentagon

TEST(FigureArrayTest, AddFigure) {
    FigureArray array;

    // Создаем фигуры динамически
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Figure* trapezoid = new Trapezoid(a, b, c, d);
    array.addFigure(trapezoid);

    EXPECT_EQ(array.size(), 1);  // Проверяем, что размер массива увеличился
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray array;

    // Создаем фигуры динамически
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);
    Figure* trapezoid = new Trapezoid(a, b, c, d);

    array.addFigure(trapezoid);
    EXPECT_EQ(array.size(), 1);  // Проверяем, что размер массива равен 1

    array.removeFigure(0);  // Удаляем фигуру по индексу
    EXPECT_EQ(array.size(), 0);  // Проверяем, что массив пуст
}

TEST(FigureArrayTest, CalculateTotalArea) {
    FigureArray array;

    // Создаем фигуры динамически
    std::pair<double, double> a1(0.0, 0.0);
    std::pair<double, double> b1(3.0, 0.0);
    std::pair<double, double> c1(4.0, 2.0);
    std::pair<double, double> d1(1.0, 2.0);
    Figure* trapezoid = new Trapezoid(a1, b1, c1, d1);

    std::pair<double, double> a2(0.0, 0.0);
    std::pair<double, double> b2(4.0, 0.0);
    std::pair<double, double> c2(5.0, 3.0);
    std::pair<double, double> d2(1.0, 3.0);
    Figure* rhombus = new Rhombus(a2, b2, c2, d2);

    array.addFigure(trapezoid);
    array.addFigure(rhombus);

    // Добавление отладочных сообщений
    std::cout << "Calculating total area...\n";

    // Предполагаемая площадь трапеции и ромба
    double expectedTotalArea = static_cast<double>(*trapezoid) + static_cast<double>(*rhombus);
    std::cout << "Expected Total Area: " << expectedTotalArea << "\n";

    double totalArea = array.totalArea();
    std::cout << "Calculated Total Area: " << totalArea << "\n";

    EXPECT_NEAR(totalArea, expectedTotalArea, 0.001);  // Проверяем, что общая площадь правильная
}

TEST(FigureArrayTest, DestructorClearsMemory) {
    FigureArray* array = new FigureArray();
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);

    Figure* trapezoid = new Trapezoid(a, b, c, d);
    array->addFigure(trapezoid);

    EXPECT_EQ(array->size(), 1);  // Проверяем, что размер массива равен 1
    delete array;  // Вызываем деструктор

    // Проверяем, что память очищена (нельзя проверить напрямую, но можно ожидать, что не будет утечек)
}

// Тесты для операторов копирования и перемещения
TEST(FigureArrayTest, CopyAssignmentOperator) {
    FigureArray array1;
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);
    Figure* trapezoid = new Trapezoid(a, b, c, d);
    array1.addFigure(trapezoid);

    FigureArray array2;
    array2 = array1;  // Оператор присваивания

    EXPECT_EQ(array2.size(), 1);  // Проверяем, что размер скопированного массива равен 1
}

TEST(FigureArrayTest, MoveAssignmentOperator) {
    FigureArray array1;
    std::pair<double, double> a(0.0, 0.0);
    std::pair<double, double> b(3.0, 0.0);
    std::pair<double, double> c(4.0, 2.0);
    std::pair<double, double> d(1.0, 2.0);
    Figure* trapezoid = new Trapezoid(a, b, c, d);
    array1.addFigure(trapezoid);

    FigureArray array2 = std::move(array1);  // Оператор перемещения

    EXPECT_EQ(array2.size(), 1);  // Проверяем, что размер перемещенного массива равен 1
    EXPECT_EQ(array1.size(), 0);   // Проверяем, что исходный массив пуст
}
