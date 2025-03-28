#include <iostream>
#include <string>

class Enemy {
private:
    std::string name;
    int strength;
public:
    Enemy(std::string name, int strength) : name(name), strength(strength) {}
    
    void takeDamage(int damage) {
        strength -= damage;
        if(strength < 0) strength = 0;
    }
    
    std::string getName() { return name; }
    int getStrength() { return strength; }
};
class AttackStrategy {
public:
    virtual void attack(Enemy& enemy) = 0;
    virtual ~AttackStrategy() = default;
};

class MageAttack : public AttackStrategy {
public:
    void attack(Enemy& enemy) override {
        std::cout << "Mage attack!" << std::endl;
        enemy.takeDamage(10);
    }
};

class RogueAttack : public AttackStrategy {
public:
    void attack(Enemy& enemy) override {
        std::cout << "Rogue attack!" << std::endl;
        enemy.takeDamage(15);
    }
};

class WarriorAttack : public AttackStrategy {
public:
    void attack(Enemy& enemy) override {
        std::cout << "Warrior attack!" << std::endl;
        enemy.takeDamage(25);
    }
};

class Character {
private:
    AttackStrategy* strategy;
public:
    void setStrategy(AttackStrategy* newStrategy) {
        strategy = newStrategy;
    }
    
    void performAttack(Enemy& enemy) {
        if(strategy) strategy->attack(enemy);
    }
    
    ~Character() { delete strategy; }
};

int main() {
    Character warrior, mage, rogue;
    
    warrior.setStrategy(new WarriorAttack());
    mage.setStrategy(new MageAttack());
    rogue.setStrategy(new RogueAttack());
    
    Enemy blackKiller("BLACK KILLER", 100);
    Enemy brownBiter("BROWN BITER", 50);
    
    warrior.performAttack(blackKiller);
    std::cout << blackKiller.getName() << " STRENGTH LEVEL: " 
              << blackKiller.getStrength() << std::endl;
    
    mage.performAttack(brownBiter);
    std::cout << brownBiter.getName() << " STRENGTH LEVEL: " 
              << brownBiter.getStrength() << std::endl;
    
    rogue.performAttack(blackKiller);
    std::cout << blackKiller.getName() << " STRENGTH LEVEL: " 
              << blackKiller.getStrength() << std::endl;
    
    return 0;
}
