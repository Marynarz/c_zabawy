int longestSubarray(int *nums, int numsSize)
{
    if (numsSize == 0 || numsSize == 1)
        return 0;

    int prev_long = 0;
    int act_long = 0;
    int longest = 0;
    int act_distance = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            act_distance = prev_long + act_long;
            if (act_distance > longest)
                longest = act_distance;

            prev_long = act_long;
            act_long = 0;
        }
        else
            ++act_long;
    }

    act_distance = prev_long + act_long;
    if (act_distance > longest)
        longest = act_distance;

    if (longest == numsSize)
        --longest;

    return longest;
}