#define _CRT_SECURE_NO_WARNINGS 1


#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*计算布尔二叉树的值*/
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//
//        if (root->left == NULL)
//            return root->val;
//        else if (root->val == 2)
//            return evaluateTree(root->left) || evaluateTree(root->right);
//        else
//            return evaluateTree(root->left) & evaluateTree(root->right);
//
//    }
//};

/*最晚上车时间*/
//class Solution {
//public:
//
//    //检查在mid时刻，是否能坐上车
//    bool check(int mid, vector<int>& bs, vector<int>& ps, int cpa)
//    {
//        int n = bs.size(), m = ps.size();
//        vector<int> tmp = ps;
//        tmp.push_back(mid);
//        int k = m;//此时tmp大小为m+1
//
//        while (k && tmp[k - 1] > tmp[k]) swap(tmp[k - 1], tmp[k]), k--;
//
//        for (int i = 0, j = 0; i < n; i++)
//            for (int c = 0; c < cpa && j <= m && tmp[j] <= bs[i]; c++, j++)//进到循环里，就代表这个时间能上车
//                if (tmp[j] >= mid)//大于等于mid，就代表mid能上车
//                    return true;
//
//        return false;
//    }
//
//    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
//
//        sort(buses.begin(), buses.end());
//        sort(passengers.begin(), passengers.end());
//
//        //根据发车时间和容量，找能坐上车的最大时刻 -- 不是你上车的时刻！！
//        int l = 0, r = 1e9;
//        while (l < r)
//        {
//            int mid = (l + r + 1) >> 1;
//            if (check(mid, buses, passengers, capacity)) l = mid;
//            else r = mid - 1;
//        }
//
//        //遍历能上车最大时刻 至 0
//        //若这个时刻有人，提前一分钟
//        unordered_set<int> hash;
//        for (auto x : passengers) hash.insert(x);
//        while (hash.count(r)) r--;
//
//        return r;
//
//    }
//};
////找最大上车时间
////从1e9 ~ 1 用二分，把自己模拟的最大上车时间插入到乘客里，求最大上车时间
////然后再模拟最大上车时间 ~ 0，找不冲突时间，挤掉一人
////作者--yxc
//// class Solution {
//// public:
////     int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
////         sort(buses.begin(), buses.end());
////         sort(passengers.begin(), passengers.end());
////         int j = 0, c;
////         for (int t: buses)
////             for (c = capacity; c && j < passengers.size() && passengers[j] <= t; ++j)
////                 --c;
////         --j;
////         int ans = c ? buses.back() : passengers[j]; // 在发车时到达公交站 or 上一个上车的乘客
////         while (j >= 0 && passengers[j--] == ans) --ans; // 往前找没人到达的时刻
////         return ans;
////     }
//// };
//// //找最后一辆车 == 找最后上车时间
//// //求最后一辆车发车时是否还有空位，有空位在发车时间上车，没空位在最后一位乘客上车时间上车
//// //再模拟到0，挤掉一人
//// //作者--灵茶山艾府

/*最小差值平方和*/
//class Solution {
//public:
//    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//
//        const int n = nums1.size();
//        map<int, int, greater<int>>sub;
//        int k = k1 + k2;
//
//        for (int i = 0; i < n; i++)
//            sub[abs(nums1[i] - nums2[i])] ++;
//
//        while (k)
//        {
//            auto it = sub.begin();
//            if (it->first == 0) break;
//
//            if (k >= it->second)
//            {
//                sub[it->first - 1] += it->second;
//                k -= it->second;
//
//                sub.erase(it);
//            }
//            else
//            {
//                sub[it->first - 1] += k;
//                sub[it->first] -= k;
//                k = 0;
//            }
//        }
//
//        long long res = 0;
//        for (auto x : sub)
//            res += ((long long)x.first * x.first) * x.second;
//
//        return res;
//
//    }
//};