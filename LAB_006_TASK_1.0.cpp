// без віртуального успадкування
#include <iostream>

// Базовий клас
class Base {
protected:
    int dat; // елемент даних
public:
    Base() : dat(1) {} // конструктор за замовчуванням
    Base(int d) : dat(d) {} // конструктор з параметром
};

// Клас A, успадкований від Base
class A : public Base {
protected:
    int a; // елемент даних
public:
    A() : a(1) {} // конструктор за замовчуванням
    A(int d) : a(d) {} // конструктор з параметром
    A(int d, int dt) : Base(dt), a(d) {} // конструктор з параметрами для базового і похідного класу
};

// Клас B, успадкований від Base
class B : public Base {
protected:
    int b; // елемент даних
public:
    B() : b(1) {} // конструктор за замовчуванням
    B(int d) : b(d) {} // конструктор з параметром
    B(int d, int dt) : Base(dt), b(d) {} // конструктор з параметрами для базового і похідного класу
};

// Клас C, успадкований від Base
class C : public Base {
protected:
    int c; // елемент даних
public:
    C() : c(1) {} // конструктор за замовчуванням
    C(int d) : c(d) {} // конструктор з параметром
    C(int d, int dt) : Base(dt), c(d) {} // конструктор з параметрами для базового і похідного класу
};

// Клас D, успадкований від A, B і C
class D : public A, public B, public C {
protected:
    int d; // елемент даних
public:
    D() : d(1) {} // конструктор за замовчуванням
    D(int d) : d(d) {} // конструктор з параметром
    D(int a, int b, int c, int d, int dtA, int dtB, int dtC)
        : A(a, dtA), B(b, dtB), C(c, dtC), d(d) {} // конструктор з параметрами для всіх базових і похідного класу
};

int main() {
    D obj; // створення об'єкту класу D
    // Виведення розмірів об'єктів кожного класу
    std::cout << "Size of Base: " << sizeof(Base) << std::endl;
    std::cout << "Size of A: " << sizeof(A) << std::endl;
    std::cout << "Size of B: " << sizeof(B) << std::endl;
    std::cout << "Size of C: " << sizeof(C) << std::endl;
    std::cout << "Size of D: " << sizeof(D) << std::endl;
    return 0;
}