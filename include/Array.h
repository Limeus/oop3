#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include "Figure.h"

class FigureArray {
private:
    std::vector<Figure*> figures;  // Хранит указатели на фигуры

    // Вспомогательная функция для копирования фигур
    void copyFigures(const FigureArray& other);

public:
    // Конструктор по умолчанию
    FigureArray() = default;

    // Конструктор копирования
    FigureArray(const FigureArray& other);

    // Оператор присваивания
    FigureArray& operator=(const FigureArray& other);

    // Конструктор перемещения
    FigureArray(FigureArray&& other) noexcept;

    // Оператор перемещения
    FigureArray& operator=(FigureArray&& other) noexcept;

    // Оператор сравнения
    bool operator==(const FigureArray& other) const;

    // Методы для работы с массивом фигур
    void addFigure(Figure* figure);
    void printAll() const;
    double totalArea() const;
    void removeFigure(size_t index);
    size_t size() const;  // Метод для получения размера массива

    // Деструктор для очистки памяти
    ~FigureArray();
};

#endif // ARRAY_H
