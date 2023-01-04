#include <stdio.h>

int main() {
    printf("Enter the coordinates of the first point (x1 y1): ");
    double x1, y1;
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    double x2, y2;
    scanf("%lf %lf", &x2, &y2);

    double slope = (y2 - y1) / (x2 - x1);
    printf("The slope of the line through the points is: %lf\n", slope);

    return 0;
}
