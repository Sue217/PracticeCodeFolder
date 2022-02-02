/**
 *    author: Jingbo Su
 *    created: February/02/2022 Wednesday
**/
#include <iostream>

void function(int a);
void function(const int a); // error: duplicate definition

// `const` only affects pointers and references
void function(int* ptr);
void function(const int* ptr); // ok
void function(int* const ptr); // error: duplicate definition

class overload {
 public:
  void function(int *);
  void function(const int *);
  void function(int *) const;
};

class Base {
 public:
  void Hide(int x) {
    std::cout << "Base::Hide" << std::endl;
  }
  virtual void Override(int x) {
    std::cout << "Base::Override" << std::endl;
  }
};

class Derived : public Base {
 using Base::Hide;
 using Base::Override;

 public:
  void Hide(int x) {
    std::cout << "Derived::Hide(Same parameter)" << std::endl;
  }
  void Hide(int x, int y) {
    std::cout << "Derived::Hide(Different parameter)" << std::endl;
  }
  void Override(int x) {
    std::cout << "Derived::Hide" << std::endl;
  }
};

int main() {
  Derived D;
  Base* pb = &D;
  Derived* pd = &D;
  
  constexpr int v = 42;

  pb->Hide(v);     // Base::Hide
  pd->Hide(v);     // Derived::Hide(Same parameter)
  pd->Hide(v, v);  // Derived::Hide(Different parameter)

  pb->Override(v); // Derived::Hide
  pd->Override(v); // Derived::Hide
  
  return 0;
}