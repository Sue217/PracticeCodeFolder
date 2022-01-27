/**
 *    author: Jingbo Su
 *    created: January/26/2022 Wednesday
**/
#include <iostream>
#include <bitset>

using namespace std;

void print() {
  cout << "Nothing" << endl;
}

template<typename T>
void print(const T& args) {
  cout << "Remaining one: ";
  cout << args << endl;
}

template<typename T, typename... A>
void print(const T& v, const A&... args) {
  cout << "Printing... ";
  cout << v << endl;
  print(args...);
}

int main() {
  print(7.56, "Hello", bitset<16>(377), 42);
  return 0;
}