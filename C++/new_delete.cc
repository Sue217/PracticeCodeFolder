/**
 *    author: Jingbo Su
 *    created: February/11/2022 Friday
**/
#include <cstdlib>
#include <memory>

// class Complex {...};

Complex* ptc = new Complex(1, 2);
// ...
Complex* ptc;
try {
  void* mem = operator new(sizeof(Complex));
  ptc = static_cast<Complex*> (mem);
  ptc->Complex::Complex(1, 2); // only Compiler candirectly call ctors
} catch (std::bad_alloc) {
  // if bad allocation, does not execute ctors
}
// ...
void* operator new(size_t size) noexcept {
  // try to allocate `size` bytes
  void* ptr;
  while ((ptr == malloc(size)) == 0) {
    _TRY_BEGIN
      if (_callnewh(size) == 0) {
        break;
      }
    _CATCH(std::bad_alloc) {
      return 0;
    }
    _CATCH_END
  }
  return ptr;
}

int main() {
  return 0;
}