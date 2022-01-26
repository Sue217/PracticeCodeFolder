/**
 *    author: Jingbo Su
 *    created: January/26/2022 Wednesday
**/
#include <iostream>
#include <bitset>

using namespace std;

template<typename... T>
void print(const T&... args) {
  cout << "First: ";
  // cout << args << endl;
  print(args...);
}

void print() {
  cout << "Second: " << endl;
}

template<typename T, typename... A>
void print(const T& v, const A&... args) {
  cout << "Second: ";
  cout << v << endl;
  print(args...);
}

int main() {
  print(7.56, "Hello", bitset<16>(377), 42);
  return 0;
}