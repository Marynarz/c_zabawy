#include <stdlib.h>
#include <stdio.h>

int *merge_array(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    size_t new_size = nums1Size + nums2Size;
    int *new_array = malloc(sizeof(int) * new_size);

    int i = 0, j = 0, z = 0;
    while (i < nums1Size || j < nums2Size)
    {
        if (i < nums1Size && j < nums2Size)
        {
            new_array[z] = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
            if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        else if (i < nums1Size)
        {
            new_array[z] = nums1[i];
            i++;
        }
        else
        {
            new_array[z] = nums2[j];
            j++;
        }
        z++;
    }

    return new_array;
}

double find_median(int *merged_array, int size)
{
    if (size % 2 == 1)
    {
        return (double)merged_array[size / 2];
    }
    else
    {
        double low = (double)merged_array[(size / 2) - 1];
        double up = (double)merged_array[size / 2];

        printf("low: %f, up: %f, size: %d, med: %d", low, up, size, size / 2);
        return (low + up) / 2;
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *merged_array = merge_array(nums1, nums1Size, nums2, nums2Size);
    double ret = find_median(merged_array, nums1Size + nums2Size);

    free(merged_array);
    return ret;
}

int main(void)
{
    int nums1[2];
    nums1[0] = 1;
    nums1[1] = 2;

    int nums2[2];
    nums2[0] = 3;
    nums2[1] = 5;

    printf("\n%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));

    return 0;
}