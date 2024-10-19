#include "../include/Array.h"
#include <iostream>

// Вспомогательная функция для копирования фигур
void FigureArray::copyFigures(const FigureArray& other) {
    for (const auto& figure : other.figures) {
        figures.push_back(figure->clone());  // Используем метод clone для копирования фигур
    }
}

// Конструктор копирования
FigureArray::FigureArray(const FigureArray& other) {
    copyFigures(other);
}

// Оператор присваивания
FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this == &other) {
        return *this;
    }
    // Очистка текущих фигур
    for (auto& figure : figures) {
        delete figure;
    }
    figures.clear();

    // Копирование фигур
    copyFigures(other);

    return *this;
}

// Конструктор перемещения
FigureArray::FigureArray(FigureArray&& other) noexcept
        : figures(std::move(other.figures)) {
    other.figures.clear();
}

// Оператор перемещения
FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    // Очистка текущих фигур
    for (auto& figure : figures) {
        delete figure;
    }
    figures.clear();

    // Перемещение данных
    figures = std::move(other.figures);
    other.figures.clear();

    return *this;
}

// Оператор сравнения
bool FigureArray::operator==(const FigureArray& other) const {
    if (figures.size() != other.figures.size()) {
        return false;
    }
    for (size_t i = 0; i < figures.size(); ++i) {
        if (*figures[i] != *other.figures[i]) {
            return false;
        }
    }
    return true;
}

// Метод для добавления фигуры
void FigureArray::addFigure(Figure* figure) {
    figures.push_back(figure);
}

// Метод для вывода всех фигур
void FigureArray::printAll() const {
    for (const auto& figure : figures) {
        std::cout << *figure << " Center: (" << figure->center().first
                  << ", " << figure->center().second << ") "
                  << "Area: " << static_cast<double>(*figure) << std::endl;
    }
}

// Метод для вычисления общей площади фигур
double FigureArray::totalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    return total;
}

// Метод для удаления фигуры по индексу
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
