/*
  ID: sujingb1
  TASK: sort3
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  int n;
  fin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    fin >> a[i];
    --a[i];
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] != b[i] && a[j] != b[j] && a[i] == b[j] && a[j] == b[i]) {
        swap(a[i], a[j]);
        ans += 1;
      }
    }
  }
  int bad = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      bad += 1;
    }
  }
  fout << ans + bad / 3 * 2 << '\n';
  return 0;
}

/*
 * We read the input into an array, and sort a copy of it in another array, so
 * we know what we have and what we want.
 *
 * A swap touches two elements, so it can correct at most two misplaced
 * elements. We run through the array looking for pairs of misplaced elements
 * that a swap would correct, and do those swaps.
 *
 * The remaining misplaced elements form little cycles: a 1 where a 2 should be,
 * a 2 where a 3 should be, and that 3 where the 1 should be. It takes two swaps
 * to correct such a cycle. So we count the number of such cycles (by counting
 * misplaced elements and dividing by three) and then add in two times that many
 * swaps.
 */