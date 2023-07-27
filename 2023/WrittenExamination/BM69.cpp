class Solution {
public:

    int solve(string nums) {

        // 空串或0开头的字符串都是 0
        if(nums == "" || nums[0] == '0')
            return 0;

        int f[100] = {0};
        f[0] = 1, f[1] = 1;

        for(int i = 1; i < nums.size(); ++ i)
        {
            //[i]转换成单字符， 如果使'0'，则代表和前面的结合
            f[i + 1] = f[i];
            if(nums[i] == '0')
            {
                // '10','20' 才合法
                if(nums[i - 1] != '1' && nums[i - 1] != '2')
                {
                    return 0;
                }
            }
            else 
            {
                // [i]非'0'，则判断是否能和前面的结合
                if(nums[i - 1] != '0' && ((nums[i - 1] - '0') * 10 + nums[i] - '0' <= 26))
                    f[i + 1] += f[i - 1];
            }
        }

        return f[nums.size()];
    }
};