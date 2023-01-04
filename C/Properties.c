#include <stdio.h>
#include <stdlib.h>

#define MAX_PROPERTIES 100

struct Property {
    int price;
    int squareFeet;
    int bedrooms;
    int bathrooms;
};

// Function prototypes
void getProperties(struct Property properties[], int numProperties);
void printProperties(struct Property properties[], int numProperties);
int getAveragePrice(struct Property properties[], int numProperties);

int main(void)
{
    struct Property properties[MAX_PROPERTIES];
    int numProperties, averagePrice;

    printf("Enter the number of properties: ");
    scanf("%d", &numProperties);

    getProperties(properties, numProperties);
    printProperties(properties, numProperties);

    averagePrice = getAveragePrice(properties, numProperties);
    printf("Average price: $%d\n", averagePrice);

    return 0;
}

// Reads in data for each property
void getProperties(struct Property properties[], int numProperties)
{
    int i;

    for (i = 0; i < numProperties; i++) {
        printf("Enter data for property %d:\n", i + 1);
        printf("  Price: ");
        scanf("%d", &properties[i].price);
        printf("  Square footage: ");
        scanf("%d", &properties[i].squareFeet);
        printf("  Number of bedrooms: ");
        scanf("%d", &properties[i].bedrooms);
        printf("  Number of bathrooms: ");
        scanf("%d", &properties[i].bathrooms);
    }
}

// Prints data for each property
void printProperties(struct Property properties[], int numProperties)
{
    int i;

    for (i = 0; i < numProperties; i++) {
        printf("Property %d:\n", i + 1);
        printf("  Price: $%d\n", properties[i].price);
        printf("  Square footage: %d sq ft\n", properties[i].squareFeet);
        printf("  Number of bedrooms: %d\n", properties[i].bedrooms);
        printf("  Number of bathrooms: %d\n", properties[i].bathrooms);
    }
}

// Calculates the average price of the properties
int getAveragePrice(struct Property properties[], int numProperties)
{
    int i, totalPrice = 0;

    for (i = 0; i < numProperties; i++) {
        totalPrice += properties[i].price;
    }

    return totalPrice / numProperties;
}
