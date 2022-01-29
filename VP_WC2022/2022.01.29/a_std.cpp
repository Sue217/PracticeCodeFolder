#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
#define LL long long
int cas = 1, T;
int pre[1005];
int Find(int tx)
{
  int r = tx;
  while (r != pre[r])
    r = pre[r];
  int i = tx, j;
  while (pre[i] != r)
  {
    j = pre[i];
    pre[i] = r;
    i = j;
  }
  return r;
}
void mix(int tx, int ty)
{
  int fx = Find(tx), fy = Find(ty);
  if (fx != fy)
  {
    pre[fy] = fx;
  }
}

int vis[1010];
int x[1010], y[1010];
int n, d;
bool dist(int a, int b)
{
  if ((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) <= d * d)
    return true;
  return false;
}
int main()
{
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++)
  {
    pre[i] = i;
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
    scanf("%d%d", &x[i], &y[i]);
  }
  char c;
  int temp;
  while (cin >> c)
  {
    if (c == 'O')
    {
      int r;
      scanf("%d", &r);
      vis[r] = 1;
      for (int i = 1; i <= n; i++)
        if (i != r && vis[i] && dist(i, r))
          mix(i, r);
    }
    if (c == 'S')
    {
      int r, l;
      scanf("%d%d", &r, &l);
      int k1 = Find(r);
      int k2 = Find(l);
      if (k1 == k2)
        printf("SUCCESS\n");
      else
        printf("FAIL\n");
    }
  }
  return 0;
}