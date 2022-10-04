
/*栈的压入、弹出序列*/
/* https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        stack<int> res;

        int j = 0;

        for(int i = 0; i < pushV.size(); ++i)
        {
            res.push(pushV[i]);
            while(!res.empty() && res.top() == popV[j])
            {
                ++j;
                res.pop();
            }
        }

        return res.empty();
        
    }
};