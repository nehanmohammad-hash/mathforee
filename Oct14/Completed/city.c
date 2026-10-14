// By Nehan mohammad
// 14-October-26, Wednesday, question no: city_structure

#include <stdio.h>

struct City {
    char name[50];
    char country[50];
    char population[50];
    double latitude;
    double longitude;
};

int main() {
    struct City my_city;

    // Accept values from the user
    printf("Enter city name: ");
    scanf(" %49[^\n]", my_city.name);

    printf("Enter country name: ");
    scanf(" %49[^\n]", my_city.country);

    printf("Enter population: ");
    scanf("%49[^\n]", &my_city.population);

    printf("Enter latitude: ");
    scanf("%lf", &my_city.latitude);

    printf("Enter longitude: ");
    scanf("%lf", &my_city.longitude);

    // Print the stored information
    printf("\n--- City Information ---\n");
    printf("City Name: %s\n", my_city.name);
    printf("Country:   %s\n", my_city.country);
    printf("Population: %ld\n", my_city.population);
    printf("Latitude:  %.4f\n", my_city.latitude);
    printf("Longitude: %.4f\n", my_city.longitude);

    return 0;
}
