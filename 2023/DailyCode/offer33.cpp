
class Solution {
public:
    //分治
    bool build(vector<int>& post, int l, int r)
    {
        if(l >= r) return true;

        //左区间 都小于[p]
        int p = l;
        while(post[p] < post[r]) ++ p;

        //右区间 都大于[p]
        //p == r 代表右区间都大于[p]
        int m = p;
        while(post[p] > post[r]) ++ p;
        
        return p == r && build(post, l, m - 1) && build(post, m, r - 1);

    }
    bool verifyPostorder(vector<int>& postorder) {

        return build(postorder, 0, postorder.size() - 1);

    }
};


// class Solution
// {
//     //模拟？        
//     //评论区+画图理解
// public:
//     void build(vector<int> &rootRL, int lMax, int rMin)
//     {

//         if (rootRL.empty()) return;
//         int rootValue = *(rootRL.end()-1);

//         if (rootValue < lMax || rootValue > rMin)
//             return;
//         rootRL.pop_back();
//         build(rootRL, rootValue, rMin);
//         build(rootRL, lMax, rootValue);
//     }
//     bool verifyPostorder(vector<int> &postorder)
//     {
//         build(postorder, INT_MIN, INT_MAX);
//         return postorder.empty();
//     }
// };