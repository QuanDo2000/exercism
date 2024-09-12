#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>
#include <stdexcept>

using namespace std;

namespace Bankaccount {
class Bankaccount {
   private:
    bool _is_open;
    int _balance;
    mutex _transaction_lock;

   public:
    Bankaccount();
    void open();
    void close();
    int balance();
    void deposit(int amount);
    void withdraw(int amount);
};  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H