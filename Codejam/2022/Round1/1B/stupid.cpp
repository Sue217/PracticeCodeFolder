#include <iostream>

using namespace std;

int max(int*, int, int*);

int main() {
  int a[6] = {1, -12, 16, 84, 7, 8};
  int loc;
  cout << "数组a的最大元素为: " << max(a, 6, &loc) << endl;
  cout << "最大元素的下标为: " << loc << endl;
  return 0;
}

int max(int* a, int n, int* loc) {
  int mx = -(int) 2e9;
  for (int i = 0; i < n; i++) {
    if (mx < a[i]) {
      mx = a[i];
      *loc = i;
    }
  }
  return mx;
}