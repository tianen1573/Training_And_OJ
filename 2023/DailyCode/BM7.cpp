class Solution {
  public:
    ListNode* EntryNodeOfLoop(ListNode* head) {
        // h + c = n*l , h = n*l - c
        //相与的节点在，环入口+c位置上，一个从开头，一个从相遇
        //当走到入口时，前者走了h，后者走了n*l-c,又因为从+c开始
        //可以认为是提前从入口处出发，走了n*l，则相遇处就是入口

        if(!head) return nullptr;

        ListNode *fast = head, *last = head;

        while(true)
        {
            last = last->next;

            fast = fast->next;
            if(!fast) return nullptr;
            fast = fast->next;

            if(!last || !fast) return nullptr;

            if(last == fast) break;
        }

        last = head;

        while (fast != last) {
            last = last->next;
            fast = fast->next;
        }

        return fast;

    }
};