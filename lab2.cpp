#include <iostream>
#include <algorithm>

class Box {
    unsigned int length;
    unsigned int width;
    unsigned int height;

public:
    Box() : length(0), width(0), height(0) {}
    Box(unsigned int l, unsigned int w, unsigned int h) : length(l), width(w), height(h) {}
    Box(const Box& other) : length(other.length), width(other.width), height(other.height) {}
    Box& operator=(const Box& other) {
        if (this != &other) {
            length = other.length;
            width = other.width;
            height = other.height;
        }
        return *this;
    }

    unsigned int getVolume() const {
        return length * width * height;
    }

    void scale(unsigned int scaleValue) {
        length *= scaleValue;
        width *= scaleValue;
        height *= scaleValue;
    }

    bool isBigger(const Box& other) const {
        return getVolume() > other.getVolume();
    }

    bool isSmaller(const Box& other) const {
        return getVolume() < other.getVolume();
    }

    Box operator*(unsigned int scaleValue) const {
        return Box(length * scaleValue, width * scaleValue, height * scaleValue);
    }

    bool operator==(const Box& other) const {
        unsigned int sides1[3] = {length, width, height};
        unsigned int sides2[3] = {other.length, other.width, other.height};
        std::sort(sides1, sides1 + 3);
        std::sort(sides2, sides2 + 3);
        return sides1[0] == sides2[0] && sides1[1] == sides2[1] && sides1[2] == sides2[2];
    }
};

class Cube {
    unsigned int side;

public:
    Cube(unsigned int s) : side(s) {}

    operator Box() const {
        return Box(side, side, side);
    }
};

int main() {
    Box box1(2, 3, 4);
    Box box2 = box1 * 2;
    Box box3(4, 6, 8);

    std::cout << "Volume of box1: " << box1.getVolume() << std::endl;
    std::cout << "Volume of box2: " << box2.getVolume() << std::endl;

    if (box2 == box3) {
        std::cout << "box2 and box3 are equal" << std::endl;
    } else {
        std::cout << "box2 and box3 are not equal" << std::endl;
    }

    Cube cube(5);
    Box box4 = cube;

    std::cout << "Volume of box4 (converted from cube): " << box4.getVolume() << std::endl;

    if (box1.isBigger(box4)) {
        std::cout << "box1 is bigger than box4" << std::endl;
    } else {
        std::cout << "box1 is not bigger than box4" << std::endl;
    }

    return 0;
}