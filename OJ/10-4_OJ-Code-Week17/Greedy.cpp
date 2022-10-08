
/*����ϴ��*/
/* https://leetcode.cn/problems/advantage-shuffle/ */

/*
* ��n1, n2 �������� ÿ�αȽ�ͷԪ�ش�С
* ��n1.front > n2.front, ��n2��Ӧ��Ԫ�ص�ԭ�±����n1��ӦԪ�ص����±�
* ��         <=        , ��n1.front��ŵ���ʱ����
* ֱ��n1�����꣬ ��tmp�����е�Ԫ�أ������û��ƥ��Ԫ�ص��±�
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