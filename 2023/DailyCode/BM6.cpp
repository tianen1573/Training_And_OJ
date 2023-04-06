class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head) return false;

        ListNode *fast = head, *last = head;

        while(true)
        {
            last = last->next;

            fast = fast->next;
            if(!fast) return false;
            fast = fast->next;

            if(!last || !fast) return false;

            if(last == fast) return true;
        }
        
    }
};