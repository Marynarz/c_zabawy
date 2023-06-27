#include <stdio.h>

int main(void)
{
    int test = 123;

    printf("x = %d\t 0x = %#o\t 0xx = %#x\n", test, test, test);
    return 0;
}