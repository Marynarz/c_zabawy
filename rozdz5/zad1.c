#include <stdio.h>

int main(void)
{
    const int MINUTES = 60;

    int set_time;

    scanf("%d", &set_time);

    while(set_time > 0)
    {
        printf("%ds = %dh : %dm : %ds\nPodaj czas: ", set_time, set_time/MINUTES/MINUTES, set_time/MINUTES, set_time % MINUTES);
        scanf("%d", &
        set_time);
    }

    return 0;
}