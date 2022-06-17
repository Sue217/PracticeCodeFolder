/**
 *    author: Jingbo Su
 *    created: June/09/2022 Thursday
 **/
#include <iostream>

class Transaction {
 public:
  Transaction();
  virtual void log() const = 0;
};

Transaction::Transaction() {
  //! log();
}

class buyTransaction : public Transaction {
 public:
  virtual void log() const;
};

void buyTransaction::log() const { std::cout << "buy" << std::endl; }

int main() {
  buyTransaction by;
  by.log();
  return 0;
}