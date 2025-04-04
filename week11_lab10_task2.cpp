// Task 2 - Decorator
#include <iostream>
#include <memory>
using namespace std;

class Text {
public:
    virtual string write() = 0;
    virtual ~Text() = default;
};

class PlainText : public Text {
    string text;
public:
    PlainText(string t) : text(t) {}
    string write() override { return text; }
};

class TextDecorator : public Text {
protected:
    shared_ptr<Text> text;
public:
    TextDecorator(shared_ptr<Text> t) : text(t) {}
};

class Bold : public TextDecorator {
public:
    using TextDecorator::TextDecorator;
    string write() override {
        return "\033[1m" + text->write() + "\033[0m";
    }
};

class Italic : public TextDecorator {
public:
    using TextDecorator::TextDecorator;
    string write() override {
        return "\033[3m" + text->write() + "\033[0m";
    }
};

class Underline : public TextDecorator {
public:
    using TextDecorator::TextDecorator;
    string write() override {
        return "\033[4m" + text->write() + "\033[0m";
    }
};

int main() {
    auto text = make_shared<PlainText>("Hello World");
    auto styled = make_shared<Underline>(make_shared<Italic>(make_shared<Bold>(text)));
    cout << styled->write() << endl;
    return 0;
}
