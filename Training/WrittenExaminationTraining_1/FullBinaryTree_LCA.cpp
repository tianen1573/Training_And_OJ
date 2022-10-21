// 将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。现给定a, b为两个结点。
// 设计一个算法，返回a、b最近的公共祖先的编号。注意其祖先也可能是结点本身。测试样例:


class LCA {
public:
    int getLCA(int a, int b) {
        
        // write code here
        while(a != b)
        {
            if(a > b)
            {
                a /= 2;
            }
            else
            {
                b /= 2;
            }
        }
        
        return a;
    }
};