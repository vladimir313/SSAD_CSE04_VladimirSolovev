#include <memory>
#include <iostream>

class Box {
public:
    int value;
    Box(int v) : value(v) { std::cout << "box " << value << " created\n"; }
    ~Box() { std::cout << "box " << value << " destroyed\n"; }
};

int create_unique(int value) {
    std::unique_ptr<Box> ptr = std::make_unique<Box>(value);
    return ptr->value;
}

void create_shared_boxes() {
    std::shared_ptr<Box> b1 = std::make_shared<Box>(1);
    std::shared_ptr<Box> b2 = std::make_shared<Box>(2);
    std::cout << "b1 count: " << b1.use_count() << "\n";
    std::shared_ptr<Box> b3 = b1;
    std::cout << "b1 count: " << b1.use_count() << "\n";
}

void use_weak_ptr() {
    std::shared_ptr<Box> shared = std::make_shared<Box>(3);
    std::weak_ptr<Box> weak = shared;
    if (auto temp = weak.lock()) {
        std::cout << "weak access: " << temp->value << "\n";
    }
    shared.reset();
    if (weak.expired()) {
        std::cout << "object destroyed\n";
    }
}
int main(){

}

