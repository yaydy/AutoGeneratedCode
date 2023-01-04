#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, compound_interest;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);

    printf("Enter the rate of interest: ");
    scanf("%f", &rate);

    printf("Enter the time period: ");
    scanf("%f", &time);

    compound_interest = principal * pow(1 + rate / 100, time) - principal;

    printf("Compound interest is: %.2f", compound_interest);

    return 0;
}
