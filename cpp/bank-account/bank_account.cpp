#include "bank_account.h"

namespace Bankaccount {
Bankaccount::Bankaccount() {
    _is_open = false;
    _balance = 0;
}

void Bankaccount::open() {
    if (_is_open) throw runtime_error("account already open");
    _is_open = true;
    _balance = 0;
}

void Bankaccount::close() {
    if (!_is_open) throw runtime_error("account not open");
    _is_open = false;
}

int Bankaccount::balance() {
    if (!_is_open) throw runtime_error("account not open");
    return _balance;
}

void Bankaccount::deposit(int amount) {
    if (!_is_open) throw runtime_error("account not open");
    if (amount < 0) throw runtime_error("can't deposit negative amount");
    _transaction_lock.lock();
    _balance += amount;
    _transaction_lock.unlock();
}

void Bankaccount::withdraw(int amount) {
    if (!_is_open) throw runtime_error("account not open");
    if (amount < 0) throw runtime_error("can't withdraw negative amount");
    if (amount > balance()) throw runtime_error("not enough balance");
    _transaction_lock.lock();
    _balance -= amount;
    _transaction_lock.unlock();
}
}