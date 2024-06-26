#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Базовий клас Геометрична фігура
class GeometricFigure {
public:
    virtual double getArea() const = 0;  // Чисто віртуальна функція для обчислення площі
    virtual double getPerimeter() const = 0; // Чисто віртуальна функція для обчислення периметру
    virtual ~GeometricFigure() {}  // Віртуальний деструктор
};

// Клас Коло, успадковується від Геометрична фігура
class Circle : public virtual GeometricFigure {
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }

    double getRadius() const {
        return radius;
    }
};

// Клас Квадрат, успадковується від Геометрична фігура
class Square : public virtual GeometricFigure {
protected:
    double side;

public:
    Square(double s) : side(s) {}

    double getArea() const override {
        return side * side;
    }

    double getPerimeter() const override {
        return 4 * side;
    }

    double getSide() const {
        return side;
    }
};

// Клас Вписане коло в квадраті, успадковується від Коло та Квадрат
class InscribedCircleInSquare : public Circle, public Square {
public:
    InscribedCircleInSquare(double side)
        : GeometricFigure(), Circle(side / 2), Square(side) {}

    // Площа вписаного кола
    double getArea() const override {
        return Circle::getArea();
    }

    // Периметр вписаного кола
    double getPerimeter() const override {
        return Circle::getPerimeter();
    }

    // Площа квадрата
    double getSquareArea() const {
        return Square::getArea();
    }

    // Периметр квадрата
    double getSquarePerimeter() const {
        return Square::getPerimeter();
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");

    double side = 4.0;

    InscribedCircleInSquare inscribedCircle(side);

    cout << "Сторона квадрата: " << inscribedCircle.getSide() << endl;
    cout << "Площа квадрата: " << inscribedCircle.getSquareArea() << " квадратних одиниць" << endl;
    cout << "Периметр квадрата: " << inscribedCircle.getSquarePerimeter() << " одиниць" << endl;

    cout << "Радіус вписаного кола: " << inscribedCircle.getRadius() << endl;
    cout << "Площа вписаного кола: " << inscribedCircle.getArea() << " квадратних одиниць" << endl;
    cout << "Периметр вписаного кола: " << inscribedCircle.getPerimeter() << " одиниць" << endl;

    return 0;
}
