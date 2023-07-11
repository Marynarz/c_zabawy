#include <stdio.h>
#define TAB_SIZE 26

int main(void)
{
    char tab[TAB_SIZE];

    for (int i = 0; i < TAB_SIZE; i++)
        tab[i] = 'a' + i;

    for (int i = 0; i < TAB_SIZE; i++)
        printf("%d : %c\n", tab[i], tab[i]);

    return 0;
}