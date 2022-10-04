
/*�����еĵ�K�����Ԫ��*/
/* https://leetcode.cn/problems/kth-largest-element-in-an-array/ */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> que(nums.begin(), nums.end());

        //��k��, ��ǰk-1��ȥ��
        while(--k)
        {
            que.pop();
        }

        return que.top();
        
    }
};

/*--����
//����������
void adjust_down(size_t parent)
{
    size_t child = parent * 2 + 1;
    while (child < _con.size())
    {
        // ѡ�����Һ����д����һ��, ���������ȥ�滻Ϊ���ڵ�
        if (child + 1 < _con.size() && _cmp(_con[child], _con[child + 1]))
        {
            ++child;
        }

        //�ж��Ƿ�ȸ��ڵ��
        if (_cmp(_con[parent], _con[child]))
        {
            std::swap(_con[child], _con[parent]);

            //ԭ�ڵ��³�, �����ж��Ƿ���Ҫ�³�
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
/*----���Ҫ��ռ临�Ӷ�
* ����ʹ��ȷ����СΪk��С����
*/