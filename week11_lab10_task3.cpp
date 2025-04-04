#include <iostream>
#include <memory>
using namespace std;

class Document {
public:
    virtual void display() = 0;
    virtual ~Document() = default;
};

class RealDocument : public Document {
    string content;
public:
    RealDocument(string c) : content(c) { load(); }
    void load() { cout << "Loading sensitive document\n"; }
    void display() override { cout << "Document: " << content << "\n"; }
};

class SecureDocumentProxy : public Document {
    shared_ptr<RealDocument> doc;
    string userRole;
    string content;
public:
    SecureDocumentProxy(string c, string role) : content(c), userRole(role) {}
    void display() override {
        if (userRole == "admin") {
            if (!doc) doc = make_shared<RealDocument>(content);
            doc->display();
        } else {
            cout << "Access denied!\n";
        }
    }
};

int main() {
    SecureDocumentProxy doc1("Top Secret", "user");
    SecureDocumentProxy doc2("Confidential", "admin");
    doc1.display();
    doc2.display();
    return 0;
}
