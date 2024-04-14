#include <vector>
#include <string>
#include "Transaction.h"

class Account
{
 private:
  int balance;
  std::vector<Transaction> log;

 public:
  Account();
  std::vector<std::string> Report();
  bool Deposit(int amout);
  bool Withdraw(int amount);
  int GetBalance() { return balance; }
};
