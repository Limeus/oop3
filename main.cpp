#include <iostream>
#include "include/Trapezoid.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/Array.h"

int main() {
    FigureArray figureArray;
    char option;

    while (true) {
        std::cout << "Choose an option:\n";
        std::cout << "1. Add Trapezoid\n";
        std::cout << "2. Add Rhombus\n";
        std::cout << "3. Add Pentagon\n";
        std::cout << "4. Print all figures\n";
        std::cout << "5. Calculate total area\n";
        std::cout << "6. Remove figure by index\n";
        std::cout << "7. Exit\n";
        std::cin >> option;

        switch (option) {
            case '1': {
                Trapezoid* trap = new Trapezoid();
                std::cout << "Enter coordinates of the trapezoid (4 pairs of x y):\n";
                std::cin >> *trap;
                figureArray.addFigure(trap);
                break;
            }
            case '2': {
                Rhombus* rhombus = new Rhombus();
                std::cout << "Enter coordinates of the rhombus (4 pairs of x y):\n";
                std::cin >> *rhombus;
                figureArray.addFigure(rhombus);
                break;
            }
            case '3': {
                Pentagon* pentagon = new Pentagon();
                std::cout << "Enter coordinates of the pentagon (5 pairs of x y):\n";
                std::cin >> *pentagon;
                figureArray.addFigure(pentagon);
                break;
            }
            case '4': {
                figureArray.printAll();
                break;
            }
            case '5': {
                std::cout << "Total area of all figures: " << figureArray.totalArea() << std::endl;
                break;
            }
            case '6': {
                std::cout << "Enter index of the figure to remove (starting from 0):\n";
                size_t index;
                std::cin >> index;
                figureArray.removeFigure(index);
                break;
            }
            case '7': {
                std::cout << "Exiting...\n";
                return 0; // Завершаем программу
            }
            default: {
                std::cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    }
}
