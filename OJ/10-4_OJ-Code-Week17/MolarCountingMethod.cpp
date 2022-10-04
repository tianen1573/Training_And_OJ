
/* 数组中出现次数超过一半的数字*/
/* https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking */

/*摩尔计数法*/
int MoreThanHalfNum_Solution(int* nums, int numbersLen ) {

    int res = nums[0], count = 1;

    for(int i = 1; i < numbersLen; ++i)
    {
        if(nums[i] == res)
        {
            ++count;
        }
        else
        {
            --count;
            if(0 == count)
            {
                res = nums[i];
                count = 1;
            }
        }
    }

    return res;

}