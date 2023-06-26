int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    int* return_arr = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numbersLen - 1; i++)
    {
        if(numbers[i]>target)
            continue;
        for (int j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                return_arr[0] = i + 1;
                return_arr[1] = j + 1;
                return return_arr;
            }
        }
    }
    return NULL;
}