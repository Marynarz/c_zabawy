#include <stdio.h>

int main(void)
{
    float wzrost;
    char imie[20];
    printf("Podaj imie: ");
    scanf("%s", imie);

    printf("\nPodaj wzrost w cm: ");
    scanf("%f", &wzrost);

    printf("%s twoj wzrost to %.2f\n", imie, wzrost / 100);

    return 0;
}