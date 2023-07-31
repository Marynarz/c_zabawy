#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp_function(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

int *build_new_cuts(int *cuts, int cuts_size, int max)
{
    printf("MAX: %d\n", max);
    int *new_cuts = malloc(sizeof(int) * cuts_size + 2);

    qsort(cuts, cuts_size, sizeof(int), &cmp_function);

    new_cuts[0] = 0;

    for (int i = 1; i < cuts_size + 1; i++)
        new_cuts[i] = cuts[i - 1];

    new_cuts[cuts_size + 1] = max;

    return new_cuts;
}

int **build_2d_array(int cuts_size)
{
    int new_size = cuts_size + 1;
    int **array = malloc(sizeof(int *) * new_size);

    for (int i = 0; i < new_size; i++)
        array[i] = malloc(sizeof(int) * new_size);

    for (int i = 0; i < new_size; i++)
        for (int j = 0; j < new_size; j++)
            array[i][j] = 0;

    return array;
}

void show_2d_array(int **array, int size)
{
    printf("\n--- SHOW 2D ARRAY ---\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf(" %d ", array[i][j]);
        // printf("(%d, %d): %d ", i, j, array[i][j]);

        printf("\n");
    }
    printf("--- END OF 2D ARRAY ---\n");
}

int minCost(int n, int *cuts, int cutsSize)
{
    int *new_cuts = build_new_cuts(cuts, cutsSize, n);

    printf("\n");
    for (int i = 0; i < cutsSize+2; i++)
        printf("%d ", new_cuts[i]);
    printf("\n");

    int **array = build_2d_array(cutsSize + 2);

    int right = 0;
    for (int diff = 2; diff < cutsSize + 2; ++diff)
    {
        for (int left = 0; left < (cutsSize + 2) - diff; ++left)
        {
            right = left + diff;
            int ans = INT_MAX;
            for (int mid = left + 1; mid < right; ++mid)
                ans = ans < array[left][mid] + array[mid][right] + new_cuts[right] - new_cuts[left] ? ans : array[left][mid] + array[mid][right] + new_cuts[right] - new_cuts[left];

            array[left][right] = ans;
        }
    }

    show_2d_array(array, cutsSize + 2);

    free(new_cuts);

    for (int i = 0; i <= cutsSize + 2; i++)
        free(array[i]);

    free(array);
}

int main(void)
{
    int *cuts = malloc(sizeof(int) * 4);
    cuts[0] = 1;
    cuts[1] = 3;
    cuts[2] = 4;
    cuts[3] = 5;

    minCost(7, cuts, 4);

    free(cuts);

    int *cuts2 = malloc(sizeof(int) * 5);
    cuts[0] = 5;
    cuts[1] = 6;
    cuts[2] = 1;
    cuts[3] = 4;
    cuts[4] = 2;

    minCost(9, cuts2, 5);

    free(cuts2);
    return 0;
}