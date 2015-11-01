#include <stdio.h>
#include <stdlib.h>

float squareRoot(float n, int iterations);

int main(int argc, char *argv[]) {
  float root;
  if (argc < 2 || argc > 3) {
    printf("Usage: root <number to find square root> [<number of iterations>]");
    return 1;
  } else if (argc == 2) {
    float n = atof(argv[1]);
    root = squareRoot(n, 1);
  } else if (argc == 3) {
    float n = atof(argv[1]);
    int i = atoi(argv[2]);
    root = squareRoot(n, i);
  }
  printf("%f\n", root);
  return 0;
}

float squareRoot(float n, int iterations) {
  float halfN = n * 0.5f;
  int bitsN = *(int *)&n;
  bitsN = 0x5f3759df - (bitsN >> 1);
  n = *(float *)&bitsN;
  for (int i = 0; i < iterations; ++i) {
    n = n * (1.5f-halfN*n*n);
  }
  return 1.0f/n;
}
