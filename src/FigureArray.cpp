#include "../include/Array.h"
#include <iostream>

// Добавление фигуры
void FigureArray::addFigure(Figure* figure) {
    figures.push_back(figure);
}

// Вывод всех фигур
void FigureArray::printAll() const {
    for (const auto& figure : figures) {
        std::cout << *figure << " Center: (" << figure->center().first
                  << ", " << figure->center().second << ") "
                  << "Area: " << static_cast<double>(*figure) << std::endl;
    }
}

// Общая площадь всех фигур
double FigureArray::totalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    return total;
}

// Удаление фигуры по индексу
void FigureArray::removeFigure(size_t index) {
    if (index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

// Метод для получения количества фигур
size_t FigureArray::size() const {
    return figures.size();
}

// Деструктор для очистки памяти
FigureArray::~FigureArray() {
    for (auto& figure : figures) {
        delete figure;
    }
}
