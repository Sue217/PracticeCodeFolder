/**
 *    title: Donut
 *    author: Jingbo Su
 *    created: March/09/2022 Wednesday
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  float A = 0.0, B = 0.0;
  const int N = 1760;
  const float pi = 3.14;
  float z[N];
  char b[N];
  printf("\n");
  for (;;) {
    memset(b, 32, N);
    memset(z, 0, 4 * N);
    for (float j = 0.0; j < pi * 2; j += 0.004) {
      for (float i = 0.0; i < pi * 2; i += 0.035) {
        float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A);
        float h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i);
        float m = cos(B), n = sin(B), t = c * h * g - f * e;
        int x = 40 + 30 * D * (l * h * m - t * n);
        int y = 12 + 15 * D * (l * h * n + t * m);
        int o = x + 80 * y, W = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
        if (0 < y && y < 22 && 0 < x && x < 80 && D > z[o]) {
          z[o] = D;
          b[o] = ".,-~:;=!*#$@:"[W > 0 ? W : 0];
        }
      }
    }
    printf("\x1b[H");
    for (int k = 0; k < N; k++) {
      putchar(k % 80 ? b[k] : 10);
    }
    A += 0.04;
    B += 0.02;
  }
  return 0;
}