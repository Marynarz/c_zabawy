#include <stdio.h>

int main(void)
{
    int i;
    char x;
    for (i = 0, x = 'A'; i < 6; i++)
    {
        for(int j = 0; j <= i; j++, x++)
            printf("%c", x);

        printf("\n");
    }
    
    return 0;
}