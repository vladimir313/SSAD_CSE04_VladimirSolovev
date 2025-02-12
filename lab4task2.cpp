#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);

    Shape* shape = &rectangle;

    const Rectangle* rectPtr = static_cast<const Rectangle*>(shape); // [1]
    cout << "Rectangle area: " << rectPtr->area() << endl;

    if (dynamic_cast<Circle*>(shape)) { 
        cout << "Shape is a Circle." << endl;
    } else {
        cout << "Shape is not a Circle." << endl;
    }
    const Rectangle& constRect = rectangle;
    Rectangle& nonConstRect = const_cast<Rectangle&>(constRect); 
    nonConstRect = Rectangle(6.0, 4.0);

    int intValue = 42;
    double doubleValue = reinterpret_cast<double&>(intValue); 
    cout << "Reinterpreted double value: " << doubleValue << endl;

    return 0;
}