/**
 *    author: Jingbo Su
 *    created: February/11/2022 Friday
**/
#include <iostream>
#include <memory>

namespace test {
  class T {
  public:
    int id;

    T(int id) : id(id) {
      std::cout << "ctor.this = " << this << ", id = " << id << std::endl;
    }

    ~T() {
      std::cout << "dtor.this = " << this << std::endl;
    }
  };
}

namespace arraynew {
  class A {
   public:
    int id;

    A() : id(42) {
      std::cout << "default ctor.this = " << this << " id = " << id << std::endl;
    }

    A(int id) : id(id) {
      std::cout << "ctor.this = " << this << " id = " << id << std::endl;
    }

    ~A() {
      std::cout << "dtor.this = " << this << " id = " << id << std::endl;
    }
  };
}

int main() {
  // test 01
  std::cout << std::endl << "TEST01\n";
  std::string* pstr = new std::string("I am subobo.");

  //! pstr->std::string::string("I am subobo.");
  //! no member named 'string' in 'std::string'

  //! pstr->std::string::~string();

  std::cout << *pstr << std::endl;

  // test 02
  std::cout << std::endl << "TEST02\n";
  test::T* ptr = new test::T(42);

  std::cout << ptr->id << std::endl;

  //! ptr->T::T(42);
  //! cannot refer to type member 'T' in 'T' with '->'

  //! T::T(42);
  //! qualified reference to 'T' is a constructor name rather than a type in this context

  // std::cout << ptr->id << std::endl;

  delete ptr;

  // test 03
  std::cout << std::endl << "TEST03\n";
  constexpr size_t size = 3;
  arraynew::A* buf = new arraynew::A[size]; // default ctor

  arraynew::A* copy = buf;
  std::cout << "buf = " << buf << " copy = " << copy << std::endl;

  for (int i = 0; i < size; ++i) {
    new(copy++) arraynew::A(i); // ctor
    // std::cerr << (*copy).id << std::endl; /* 42 42 0 */
  }
  std::cout << "buf = " << buf << " copy = " << copy << std::endl;

  delete[] buf; // deallocate 3 times

  return 0;
}