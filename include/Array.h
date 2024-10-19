#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include "Figure.h"

class FigureArray {
private:
    std::vector<Figure*> figures;  // Хранит указатели на фигуры

public:
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
