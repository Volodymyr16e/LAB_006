#include <iostream>
#include <string>

using namespace std;

// Абстрактний базовий клас Employee
class Employee {
protected:
    string name;

public:
    Employee(string name) : name(name) {}

    // Чисто віртуальна функція для нарахування зарплати
    virtual double calculateSalary() const = 0;

    // Функція для отримання імені працівника
    string getName() const {
        return name;
    }

    // Віртуальний деструктор для правильного видалення через вказівник на базовий клас
    virtual ~Employee() {}
};

// Похідний клас HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(string name, double hourlyRate, double hoursWorked)
        : Employee(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    // Реалізація методу для нарахування зарплати для погодинно оплачуваного працівника
    virtual double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Похідний клас SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double annualSalary;

public:
    SalariedEmployee(string name, double annualSalary)
        : Employee(name), annualSalary(annualSalary) {}

    // Реалізація методу для нарахування зарплати для працівника з фіксованою зарплатою
    virtual double calculateSalary() const override {
        return annualSalary;
    }
};

// Похідний клас CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(string name, double salesAmount, double commissionRate)
        : Employee(name), salesAmount(salesAmount), commissionRate(commissionRate) {}

    // Реалізація методу для нарахування зарплати для працівника з відсотковою ставкою
    virtual double calculateSalary() const override {
        return salesAmount * (commissionRate / 100.0);
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // Приклад використання класів

    HourlyEmployee hourlyEmp("Василя", 15.0, 40.0); // Погодинно оплачуваний працівник
    SalariedEmployee salariedEmp("Андрія", 50000.0); // Працівник з фіксованою зарплатою
    CommissionEmployee commissionEmp("Івана", 10000.0, 10.0); // Працівник з відсотковою ставкою

    // Виведення зарплат для кожного працівника
    cout << "погодинна оплата для " << hourlyEmp.getName() << " становить " << hourlyEmp.calculateSalary() << " долларів" << endl;
    cout << "місяна зарплата для " << salariedEmp.getName() << " становить " << salariedEmp.calculateSalary() << " Долларів" << endl;
    cout << "процентна ставка для " << commissionEmp.getName() << " становить " << commissionEmp.calculateSalary() << " Долларів" << endl;

    return 0;
}
