class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

		if(nullptr == pHead)
			return nullptr;

		ListNode* prev = nullptr;
		ListNode* cur = pHead;
		ListNode* next = cur->next;

		while(cur)
		{
			next = cur->next;

			cur->next = prev;
			prev = cur;

			cur = next;

		}

		return prev;

    }
};