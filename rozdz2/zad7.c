#include <stdio.h>

int main(void)
{
    const float inch_to_cal = 2.54;
    float scanned_height;

    printf("Podaj wzrost w cm: ");
    scanf("%f", &scanned_height);

    printf("Wzrost %1.2fcm to %1.2finch\n", scanned_height,scanned_height / inch_to_cal);

    return 0;
}