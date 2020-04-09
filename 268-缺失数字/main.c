//AC，time71%，memery100%

int missingNumber(int *nums, int numsSize)
{
    int flag0 = 0;
    int flag1 = 0;
    if (numsSize == 1)
    {
        return nums[0] == 1 ? 0 : 1;
    }
    else if (numsSize % 2 == 1)
    {
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == 0)
            {
                flag0 = 1;
            }
            else if (nums[i] == numsSize)
            {
                flag1 = 1;
            }
            sum += nums[i];
            sum %= numsSize;
        }
        if (flag0 & flag1 == 1) //未出现0或n
        {
            return numsSize - sum;
        }
        else
        {
            return flag0 == 0 ? 0 : numsSize;
        }
    }
    else
    {
        int sum = 0; //补齐为偶数个
        sum += numsSize + 1;
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == 0)
            {
                flag0 = 1;
            }
            else if (nums[i] == numsSize)
            {
                flag1 = 1;
            }
            sum += nums[i];
            sum %= numsSize + 1;
        }
        if (flag0 & flag1)
        {
            return sum == 0 ? 0 : numsSize + 1 - sum;
        }
        else
        {
            return flag0 == 0 ? 0 : numsSize;
        }
    }
}