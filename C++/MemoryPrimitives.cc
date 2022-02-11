/**
 *    author: Jingbo Su
 *    created: February/11/2022 Friday
**/
#include <cstdlib>
#include <memory>
#include <complex>

// malloc and free
void* p1 = malloc(512);
free(p1);

// new and delete
complex<int>* p2 = new complex<int>; // one object
delete p2;

// operator new() and delete()
void* p3 = ::operator new(512);
::operator delete(p3);

// allocate and deallocate
#ifdef _MSC_VER
  // 2 non-static functions, must be called by objects
  int* p4 = allocator<int>().allocate(3, (int*) 0); // 3 integers
  allocator<int>().deallocate(p4, 3);
#endif

#ifdef __BORLANDC__
  // 2 non-static functions, must be called by objects
  int* p4 = allocator<int>().allocate(5); // 5 integers
  allocator<int>().deallocate(p4, 5);
#endif

#ifdef __GNUC__
  // gnu_c 2.9 2 static functions, can be called by full name
  // void* p4 = alloc::allocate(512); /* alloc 512 bytes */
  // alloc::deallocate(p4, 512);

  // gnu_c 4.9 4 non-static functions, must be called by objects
  void* p4 = allocator<int>().allocate(7); // 7 integers
  allocator<int>().deallocate((int*) p4, 7);

  void* p5 = __gnu_cxx::__pool_alloc<int>().allocate(9); // 9 integers
  __gnu_cxx::__pool_alloc<int>().deallocate((int*) p5, 9);
#endif

int main() {
  return 0;
}