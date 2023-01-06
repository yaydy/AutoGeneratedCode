#include <stdio.h>

int main(void) {
  int x1, y1, x2, y2;
  int gcd; // greatest common divisor
  int y_diff, x_diff;
  int y_sign, x_sign;

  // Read in the coordinates of the two points
  printf("Enter the coordinates of the first point: ");
  scanf("%d%d", &x1, &y1);
  printf("Enter the coordinates of the second point: ");
  scanf("%d%d", &x2, &y2);

  // Calculate the difference between the y-coordinates and the x-coordinates
  y_diff = y2 - y1;
  x_diff = x2 - x1;

  // Determine the signs of the differences
  y_sign = (y_diff > 0) - (y_diff < 0);
  x_sign = (x_diff > 0) - (x_diff < 0);

  // Take the absolute value of the differences
  y_diff = y_sign * y_diff;
  x_diff = x_sign * x_diff;

  // Find the greatest common divisor (GCD) of the differences using Euclid's algorithm
  while (y_diff != 0) {
    int temp = y_diff;
    y_diff = x_diff % y_diff;
    x_diff = temp;
  }
  gcd = x_diff;

  // Simplify the slope by dividing both the numerator and denominator by the GCD
  y_diff = y_sign * y_diff / gcd;
  x_diff = x_sign * x_diff / gcd;

  printf("The simplified slope is: %d/%d\n", y_diff, x_diff);

  return 0;
}
