#include <stdio.h>

void print(int *b)
{
  int i, j;
  for (i = 0; i < 8; ++i)
    for (j = 0; j < 8; ++j)
      printf("%c%c",
          (b[j] == i+1) ? '1' : '0',
          (j == 7) ? '\n' : ' ');
  printf("\n");
}

int is_ok(int *b, int q, int p) // check digonally
{
  int i, j;
  for (i=p-1, j=q-1; i>=0 && j>=1; --i, --j)
    if (b[i] == j) return 0; // false
  for (i=p+1, j=q-1; i<8 && j>=1; ++i, --j)
    if (b[i] == j) return 0; // false
  return 1; // true
}

void _8q(int *b, int q)
{
  if (q >= 9) print(b);
  for (int i = 0; i < 8; ++i) // try each position
  {
    if (!b[i] && is_ok(b, q, i)) // if safe
    {
      b[i] = q; // set
      _8q(b, q+1); // recursive
      b[i] = 0; // restore
    }
  }
}

int main(int argc, char** argv)
{
  int b[8] = {};
  _8q(b, 1);
  return 0;
}

