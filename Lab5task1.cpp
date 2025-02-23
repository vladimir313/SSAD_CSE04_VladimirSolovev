#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
template<typename T>
class GenericStack {
protected:
    std::vector<T> elements;
public:
    GenericStack() = default;
    explicit GenericStack(size_t capacity) { elements.reserve(capacity); }
    virtual ~GenericStack() = default;

    virtual void push(const T& item) {
        elements.push_back(item);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("stack is empty");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
    }

    T peek() const {
        if (elements.empty()) {
            throw std::out_of_range("stack is empty");
        }
        return elements.back();
    }
};

class StringStack : public GenericStack<std::string> {
public:
    StringStack() = default;
    explicit StringStack(size_t capacity) : GenericStack(capacity) {}

    void push(const std::string& item) override {
        if (item.empty()) {
            throw std::invalid_argument("empty string not allowed");
        }
        elements.push_back(item);
    }

    void concatTopTwo() {
        if (elements.size() < 2) {
            throw std::out_of_range("not enough elements");
        }
        std::string a = pop();
        std::string b = pop();
        push(b + a);
    }
};
int main(){

}
