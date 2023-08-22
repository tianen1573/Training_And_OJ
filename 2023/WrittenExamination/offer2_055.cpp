/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    vector<int> arr;
    int curPos = 0;
    void buildArr(TreeNode *root)
    {
        if(root == nullptr)
            return ;
        
        buildArr(root->left);
        arr.push_back(root->val);
        buildArr(root->right);
    }
    BSTIterator(TreeNode* root) {
        buildArr(root);
    }
    
    int next() {
        return arr[curPos ++ ];
    }
    
    bool hasNext() {
        return curPos < arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    stack<TreeNode*> stk;
    TreeNode *curNode;
    BSTIterator(TreeNode* root) : curNode(root) {}
    
    int next() {
        // 调用保证了存在next，即保证此时stk一定不为空
        while(curNode != nullptr)
        {
            stk.push(curNode);
            curNode = curNode->left;
        }
        // 取出该的根节点
        curNode = stk.top();
        stk.pop();
        // 此时为 未访问的 最左节点
        int retVal = curNode->val;
        // 遍历右子树
        curNode = curNode->right;

        return retVal;
    }
    
    bool hasNext() {

        return stk.size() || curNode;

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */