#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string ownerName;
public:
    Account() = default;
    Account(int accNum, double bal, string name) : accountNumber(accNum), balance(bal), ownerName(name) {}
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;

    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
    double getBalance() const{
        return balance;
    }
    int getAccountNumber() const {
        return accountNumber;
    }

    string getOwnerName() const {
        return ownerName;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(int accNum, double bal, string name, double rate) : Account(accNum, bal, name), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        deposit(interest);
    }

    double getInterestRate() const {
        return interestRate;
    }
};

int main() {
    SavingsAccount savings(123456, 1000.0, "John Doe", 2.5);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();
    cout << "Account Number: " << savings.getAccountNumber() << endl;
    cout << "Owner's Name: " << savings.getOwnerName() << endl;
    cout << "Current Balance: " << savings.getBalance() << endl;
    cout << "Interest Rate: " << savings.getInterestRate() << "%" << endl;
}