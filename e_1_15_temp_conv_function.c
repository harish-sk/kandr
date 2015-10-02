#include <stdio.h>

float fahr_to_celsius(float fahr);

int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;   /* lower limit of temp table */
  upper = 300; /* upper limit */
  step = 20;

  fahr = lower;
  while(fahr <= upper) {
    celsius = fahr_to_celsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

float fahr_to_celsius(float fahr)
{
  return (5.0 * (fahr - 32) / 9);
}
