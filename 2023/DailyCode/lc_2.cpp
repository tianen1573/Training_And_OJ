/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //1. 翻转链表 -- 原地操作
    //2. 辅助栈 -- 也可以转成string/vector 再转回来
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1, s2;
        ListNode* head = nullptr;

        while(l1)
            s1.push(l1->val), l1 = l1->next;
        while(l2)
            s2.push(l2->val), l2 = l2->next;
        
        int carry = 0;
        while(s1.size() || s2.size() || carry)
        {
            int n1 = 0, n2 = 0;
            if(s1.size()) { n1 = s1.top(); s1.pop();}
            if(s2.size()) { n2 = s2.top(); s2.pop();}

            carry += (n1 + n2);

            ListNode* node = new ListNode(carry % 10);
            carry /= 10;

            node->next = head;
            head = node;
        }

        return head;
    }
};

// //by luonanqin
// class Solution {
//     public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
//         ListNode i = l1;
//         ListNode j = l2;

//         // 先两个指针A B分别从两个链表头向后遍历
//         while (i != null && j != null) {
//             i = i.next;
//             j = j.next;
//         }
//         if (i == null && j == null) { // 两个指针同时到达尾结点，即链表长度一样，这种场景计算最简单
//             // 都重新指向另一个链表的头节点
//             i = l2;
//             j = l1;

//             // 递归计算加和
//             ListNode recurrence = recurrence(i, j);
            
//             if (recurrence.val == 0) {
//                 return recurrence.next;
//             }
//             return recurrence;
//         } else if (i == null) {
//             // i指向的链表较短先遍历到尾结点
//             i = l2;
//             // 同时继续向后移动
//             while (j != null) {
//                 i = i.next;
//                 j = j.next;
//             }
//             j = l1;

//             // 递归计算加和
//             ListNode res = recurrence(i, j);
//             // 继续计算长度更长的链表的前半部分
//             ListNode pre = re(l2, i, res);
//             if (pre.val == 0) {
//                 return pre.next;
//             }
//             return pre;
//         } else if (j == null) { // 和上一种场景一样，长短链表互换一下。因为没有多遍历一次计算链表长度，所以代码多写一次
//             j = l1;
//             while (i != null) {
//                 j = j.next;
//                 i = i.next;
//             }
//             i = l2;

            
//             ListNode res = recurrence(i, j);
//             ListNode pre = re(l1, j, res);
//             if (pre.val == 0) {
//                 return pre.next;
//             }
//             return pre;
//         }

//         return null;
//     }

//     public ListNode re(ListNode l, ListNode e, ListNode res) {
//         // 长链表的头指针向后移动，直到指向短链表头结点对位的长链表节点的前驱结点。
//         // 举个例子：102345和678 l最开始指向1，e指向6，l向后移动最终指向2
//         // 然后再递归计算102和res的头结点（头结点是345+678的最高位）
//         if (l.next != e) {
//             ListNode next = re(l.next, e, res);
//             int sum = l.val + next.val;
//             int ten = sum / 10;
//             next.val = sum % 10;
//             ListNode pre = new ListNode(ten, next);
//             return pre;
//         }

//         // 尾结点计算个位与十位
//         int sum = l.val + res.val;
//         int ten = sum / 10;
//         int mod = sum % 10;
//         // 生成十位节点与个位节点，返回十位节点参与下一次两个链表的前驱节点的计算
//         ListNode next = new ListNode(mod, res.next);
//         ListNode pre = new ListNode(ten, next);
//         return pre;
//     }

//     private ListNode recurrence(ListNode l1, ListNode l2) {
//         if (l1.next != null && l2.next != null) {
//             ListNode next = recurrence(l1.next, l2.next);
//             // 前驱结点与十位进行计算
//             int sum = l1.val + l2.val + next.val;
//             int mod = sum % 10;
//             int ten = sum / 10;
//             next.val = mod;
//             // 生成新的十位节点返回给下一个前驱节点计算
//             ListNode pre = new ListNode(ten, next);
//             return pre;
//         }

//         // 尾结点计算个位与十位
//         int i = l1.val + l2.val;
//         int mod = i % 10;
//         int ten = i / 10;
//         // 生成十位节点与个位节点，返回十位节点参与下一次两个链表的前驱节点的计算
//         ListNode next = new ListNode(mod, null);
//         ListNode pre = new ListNode(ten, next);
//         return pre;
//     }
// }