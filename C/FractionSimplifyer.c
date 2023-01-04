#include <stdio.h>

int main(void) {
  int numerator, denominator;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  // Find the greatest common divisor of the numerator and denominator
  int gcd = 1;
  for (int i = 2; i <= numerator && i <= denominator; i++) {
    if (numerator % i == 0 && denominator % i == 0) {
      gcd = i;
    }
  }

  // Simplify the fraction
  numerator /= gcd;
  denominator /= gcd;

  printf("Simplified fraction: %d/%d\n", numerator, denominator);
  return 0;
}
