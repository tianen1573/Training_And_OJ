
/*优势洗牌*/
/* https://leetcode.cn/problems/advantage-shuffle/ */

/*
* 将n1, n2 升序排序， 每次比较头元素大小
* 若n1.front > n2.front, 则n2对应的元素的原下标就是n1对应元素的新下标
* 若         <=        , 则将n1.front存放到临时数组
* 直到n1遍历完， 将tmp数组中的元素，分配给没有匹配元素的下标
-----------------------------
*/


class Solution {
public:
    vector<int> advantageCount(vector<int>& n1, vector<int>& n2) {

        vector<int> res(n1.size(), -1);
        vector<int> tmp;


        vector<pair<int, int>> arr;
        for(int i = 0; i < n2.size(); ++i)
        {
            arr.push_back({n2[i], i});
        }

        sort(arr.begin(), arr.end(), [&](pair<int, int>& a1, pair<int, int>& a2)
        {
            return a1.first <= a2.first;
        });
        sort(n1.begin(), n1.end());

        for(int i = 0, j = 0; i < n1.size(); ++i)
        {
            if(n1[i] > arr[j].first)
            {
                res[arr[j].second] = n1[i];
                ++j;
            }
            else
            {
                tmp.push_back(n1[i]);
            }
        }

        for(auto& x : res)
        {
            if(x == -1)
            {
                x = tmp.back();
                tmp.pop_back();
            }
        }


        return res;

    }
};