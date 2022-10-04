
/*数组中的第K个最大元素*/
/* https://leetcode.cn/problems/kth-largest-element-in-an-array/ */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> que(nums.begin(), nums.end());

        //第k大, 把前k-1个去掉
        while(--k)
        {
            que.pop();
        }

        return que.top();
        
    }
};

/*--建堆
//建堆往下走
void adjust_down(size_t parent)
{
    size_t child = parent * 2 + 1;
    while (child < _con.size())
    {
        // 选出左右孩子中大的那一个, 将大的升上去替换为父节点
        if (child + 1 < _con.size() && _cmp(_con[child], _con[child + 1]))
        {
            ++child;
        }

        //判断是否比父节点大
        if (_cmp(_con[parent], _con[child]))
        {
            std::swap(_con[child], _con[parent]);

            //原节点下沉, 继续判断是否需要下沉
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
*/
/*----如果要求空间复杂度
* 可以使用确定大小为k的小根堆
*/