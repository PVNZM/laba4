#include <iostream>
#include <stdexcept>

class RightTriangle {
private:
    double a; // длина первого катета
    double b; // длина второго катета

public:
    // Конструктор по умолчанию
    RightTriangle() : a(1.0), b(1.0) {}

    // Конструктор с параметрами
    RightTriangle(double a, double b) {
        if (a <= 0 || b <= 0) {
            throw std::invalid_argument("Catheti must be positive.");
        }
        this->a = a;
        this->b = b;
    }

    // Конструктор копирования
    RightTriangle(const RightTriangle &t) : a(t.a), b(t.b) {}

    // Метод для вычисления площади
    double area() const {
        return (a * b) / 2;
    }

    // Унарный оператор увеличения
    RightTriangle operator++() {
        return RightTriangle(a * 2, b * 2); // Возврат нового объекта с увеличенными сторонами
    }

    // Унарный оператор уменьшения
    RightTriangle operator--() {
        return RightTriangle(a / 2, b / 2); // Возврат нового объекта с уменьшенными сторонами
    }

    // Операция приведения типа double
    explicit operator double() const {
        return area();
    }

    // Операция приведения типа bool
    explicit operator bool() const {
        return a > 0 && b > 0;
    }

    // Бинарный оператор сравнения <=
    bool operator<=(const RightTriangle &t) const {
        return area() <= t.area();
    }

    // Бинарный оператор сравнения >=
    bool operator>=(const RightTriangle &t) const {
        return area() >= t.area();
    }

    // Перегрузка оператора вывода
    friend std::ostream &operator<<(std::ostream &os, const RightTriangle &t) {
        os << "RightTriangle(a: " << t.a << ", b: " << t.b << ", area: " << t.area() << ")";
        return os;
    }
};

int main() {
    double a, b;

    // Ввод данных
    std::cout << "Введите длины катетов a и b: ";
    std::cin >> a >> b;

    try {
        RightTriangle triangle(a, b);
        std::cout << triangle << std::endl;
        std::cout << "Площадь треугольника: " << triangle.area() << std::endl;

        // Тестирование унарных операций
        RightTriangle increasedTriangle = ++triangle;  // Увеличение
        std::cout << "Увеличенные стороны треугольника: " << increasedTriangle << std::endl;

        RightTriangle decreasedTriangle = --triangle;  // Уменьшение
        std::cout << "Уменьшенные стороны треугольника: " << decreasedTriangle << std::endl;

        // Приведение типа
        double areaValue = static_cast<double>(triangle);
        std::cout << "Площадь (приведение типа): " << areaValue << std::endl;

        // Приведение типа к bool
        bool exists = static_cast<bool>(triangle);
        std::cout << "Треугольник существует: " << (exists ? "да" : "нет") << std::endl;

        // Создание другого треугольника для сравнения
        RightTriangle triangle2(3.0, 4.0);
        std::cout << "Другой треугольник: " << triangle2 << std::endl;

        std::cout << "Сравнение площадей: " << (triangle <= triangle2 ? "Треугольник 1 меньше либо равен треугольнику 2" : "Треугольник 1 больше треугольника 2") << std::endl;
      
    } catch (std::invalid_argument &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}




