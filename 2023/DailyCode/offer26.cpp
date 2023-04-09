class Solution {
public:

    bool isSub(TreeNode* A, TreeNode* B, TreeNode *head)
    {
        if(!B) return true;//B空为真
        else if(!A) return false;//B非空A空为假

        //当前节点相等
        if(A->val == B->val)
            if(isSub(A->left, B->left, head) && isSub(A->right, B->right, head))//为真才退出
                return true;
       
        //未退出，继续向下匹配
        return isSub(A->left, head, head) || isSub(A->right, head, head);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {

        if(!A || !B) return false;

        return isSub(A, B, B);


    }
};