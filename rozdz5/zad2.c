#include <stdio.h>

int main()
{
    int num;

    printf("Podaj liczbe: ");
    scanf("%d", &num);
    printf("\n");

    for (int i = 0; i <= 10; i++)
        printf("%d\t", num + i);

    printf("\n");
    return 0;
}