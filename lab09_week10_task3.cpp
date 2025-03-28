#include <iostream>
#include <vector>
#include <string>

class Component {
protected:
    std::string name;
public:
    Component(const std::string& name) : name(name) {}
    virtual void display(int depth = 0) const = 0;
    virtual ~Component() = default;
};

class File : public Component {
public:
    File(const std::string& name) : Component(name) {}
    
    void display(int depth) const override {
        std::cout << std::string(depth, '\t') << "File: " << name << std::endl;
    }
};

class Directory : public Component {
private:
    std::vector<Component*> components;
public:
    Directory(const std::string& name) : Component(name) {}
    
    void addComponent(Component* component) {
        components.push_back(component);
    }
    
    void display(int depth = 0) const override {
        std::cout << std::string(depth, '\t') << "Directory: " << name << std::endl;
        for(const auto& component : components) {
            component->display(depth + 1);
        }
    }
    
    ~Directory() {
        for(auto& component : components) {
            delete component;
        }
    }
};

int main() {
    Directory* root = new Directory("Root");
    File* file1 = new File("File1.txt");
    File* file2 = new File("File2.txt");
    Directory* dir1 = new Directory("Dir1");
    File* file3 = new File("File3.txt");
    Directory* dir2 = new Directory("Dir2");
    
    root->addComponent(file1);
    root->addComponent(file2);
    root->addComponent(dir1);
    dir1->addComponent(file3);
    dir1->addComponent(dir2);
    
    root->display();
    
    delete root;
    return 0;
}
