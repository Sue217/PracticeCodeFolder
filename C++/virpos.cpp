/**
 *    author: Jingbo Su
 *    created: June/09/2022 Thursday
 **/
#include <iostream>

class base {
 public:
  base() {
    //? foo();    <~~~~~~ OK
  }
  virtual void foo() const { std::cout << "base" << std::endl; }
  ~base();
};

class derived : public base {
 public:
  derived() {
    //! foo();    <~~~~~~ linker command failed with exit code 1
  }
  virtual void foo() const { std::cout << "derived" << std::endl; }
  ~derived();
};

int main() {
  base* pb = new base();
  base* pbd = new derived();
  derived* pd = new derived();
  pb->foo();
  pbd->foo();
  pd->foo();
  return 0;
}

/*
 *
 * No foo():
 * base
 * derived
 * derived
 * 
 * ?foo() in base:
 * base
 * base
 * base
 * base
 * derived
 * derived
 * 
*/