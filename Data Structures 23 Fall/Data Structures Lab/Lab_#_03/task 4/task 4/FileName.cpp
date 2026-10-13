#include <iostream>

template <typename T>
class OnlineBank {
private:
    T currentBalance;
    T* withdrawals;
    T* deposits;
    int numOfTransactions;
    int counterWithdrawal;
    int counterDeposits;

public:
    OnlineBank(T initialBalance, int maxTransactions)
        : currentBalance(initialBalance), numOfTransactions(maxTransactions),    // memeber initializer list
        counterWithdrawal(0), counterDeposits(0) {
        withdrawals = new T[numOfTransactions];
        deposits = new T[numOfTransactions];
    }

    ~OnlineBank() {
        delete[] withdrawals;
        delete[] deposits;
    }

    bool isWithdrawal() const {
        return counterWithdrawal < numOfTransactions;
    }

    bool isDeposit() const {
        return counterDeposits < numOfTransactions;
    }

    bool makeWithdrawal(T amount) {
        if (amount <= currentBalance && isWithdrawal()) {
            currentBalance -= amount;
            withdrawals[counterWithdrawal++] = amount;
            return true;
        }
        return false;
    }

    void makeDeposit(T amount) {
        if (isDeposit()) {
            currentBalance += amount;
            deposits[counterDeposits++] = amount;
        }
    }

    T getCurrentBalance() const {
        return currentBalance;
    }

    void print() const {
        cout << "Current Balance: " << currentBalance << std::endl;
    }
};

int main() {
    // Create an instance of OnlineBank with initial balance of 1000 and maximum of 5 transactions
    OnlineBank<double> bank(1000.0, 5);

    // Perform transactions
    bank.makeDeposit(500.0);
    bank.makeWithdrawal(200.0);
    bank.makeWithdrawal(300.0);
    bank.makeDeposit(100.0);
    bank.makeWithdrawal(400.0);

    // Print current balance
    bank.print();

    return 0;
}