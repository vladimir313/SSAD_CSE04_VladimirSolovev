#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void makeSound() = 0;
};

class LandAnimal : public Animal {
public:
    LandAnimal(string n, int a) : Animal(n, a) {}
    void walk() {
        cout << name << " is walking." << endl;
    }
};
class WaterAnimal : public Animal {
public:
    WaterAnimal(string n, int a) : Animal(n, a) {}
    void swim() {
        cout << name << " is swimming." << endl;
    }
};
class Lion : public LandAnimal {
public:
    Lion(string n, int a) : LandAnimal(n, a) {}
    void makeSound() override {
        cout << name << " roars!" << endl;
    }
};
class Dolphin : public WaterAnimal {
public:
    Dolphin(string n, int a) : WaterAnimal(n, a) {}
    void makeSound() override {
        cout << name << " clicks!" << endl;
    }
};

class Frog : public LandAnimal, public WaterAnimal {
public:
    Frog(string n, int a) : LandAnimal(n, a), WaterAnimal(n, a) {}
    void makeSound() override {
        cout << name << " croaks!" << endl;
    }
};

int main() {
    vector<Animal*> zoo;
    zoo.push_back(new Lion("Leo", 5));
    zoo.push_back(new Dolphin("Dolly", 3));
    zoo.push_back(new Frog("Fred", 2));
    for (Animal* animal : zoo) {
        animal->makeSound();
        if (Lion* lion = dynamic_cast<Lion*>(animal)) {
            lion->walk();
        }
        if (Dolphin* dolphin = dynamic_cast<Dolphin*>(animal)) {
            dolphin->swim();
        }
        if (Frog* frog = dynamic_cast<Frog*>(animal)) {
            frog->walk();
            frog->swim();
        }
    }
    for (Animal* animal : zoo) {
        delete animal;
    }
    return 0;
}