#include <stdio.h>

int main(void)
{
    int test;

    printf("Podaj liczbe: ");
    scanf("%d", &test);

    printf("\nx = %d\t 0x = %#o\t 0xx = %#x\n", test, test, test);
    return 0;
}