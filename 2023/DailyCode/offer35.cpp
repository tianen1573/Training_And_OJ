class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(nullptr == head) return nullptr;

        Node* start = head;
        Node* newHead = new Node(head->val);
        ptrMap[head] = newHead;

        //原链表先走一步，便于新链表获得后面的节点
        //先next
        Node* begin = newHead;
        start = start->next;
        while(start)
        {
            begin->next = new Node(start->val);

            ptrMap[start] = begin->next;

            start = start->next;
            begin = begin->next;
        }
        ptrMap[nullptr] = nullptr;

        //后random
        begin = newHead;
        start = head;
        while(begin)
        {
            begin->random = ptrMap[start->random];
            begin = begin->next;
            start = start->next;
        }

        return newHead;
        
    }
    private:
    //建立 老节点与新节点的地址 映射
    unordered_map<Node*, Node*> ptrMap;
};