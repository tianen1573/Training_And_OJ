
/*ɾ�����������е��ظ���*/
/* https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/ */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        
        int j = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[j])
            {
                nums[++j] = nums[i];
            }
        }

        return ++j;

        //return unique(nums.begin(), nums.end()) - nums.begin();//STL

    }
};