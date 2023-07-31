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
    int new_size = cuts_size + 2;
    int *new_cuts = malloc(sizeof(int) * new_size);

    qsort(cuts, cuts_size, sizeof(int), &cmp_function);

    new_cuts[0] = 0;

    for (int i = 1; i < cuts_size + 1; i++)
        new_cuts[i] = cuts[i - 1];

    new_cuts[new_size - 1] = max;

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

int minCost(int n, int *cuts, int cutsSize)
{
    int *new_cuts = build_new_cuts(cuts, cutsSize, n);

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
    int ret = array[0][cutsSize + 1];
    free(new_cuts);

    for (int i = 0; i <= cutsSize + 2; i++)
        free(array[i]);

    free(array);

    return ret;
}

int main(void)
{
    int *cuts = malloc(sizeof(int) * 4);
    cuts[0] = 1;
    cuts[1] = 3;
    cuts[2] = 4;
    cuts[3] = 5;

    printf("7: %d\n", minCost(7, cuts, 4));

    free(cuts);
    return 0;
}