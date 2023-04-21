/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
  public:
    TreeNode* Convert(TreeNode* pRootOfTree) {

        if (!pRootOfTree) return nullptr;

        TreeNode* head = nullptr;//链表头指针
        TreeNode* prev = nullptr;//父节点

        TreeNode* cur = pRootOfTree;//当前节点

        stack<TreeNode*> sta;

        while (cur || !sta.empty()) {//遍历到了空结点，并且，栈里也没节点

			//遍历左节点
            while (cur) {
                sta.push(cur);
                cur = cur->left;
            }

			//栈顶的是，当前的最左节点
            auto top = sta.top();
            sta.pop();

			//初始链头
            if (head == nullptr) {
                head = top;
                head->left = nullptr;
            }//第一个节点没有prev
            if (prev) {
                prev->right = top;
                top->left = prev;
            }

			//更新
            prev = top;

            cur = top->right;
        }

        return head;
    }

};
