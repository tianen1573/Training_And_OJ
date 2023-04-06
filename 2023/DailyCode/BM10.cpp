class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;

		while(p1 != p2)
		{
			
			p1 = p1 ? p1->next : pHead2;
			p2 = p2 ? p2->next : pHead1;
		}

		return p1;

	// 	int len1 = 0, len2 = 0;
	// 	ListNode *p1 = pHead1, *p2 = pHead2;

	// 	while(p1)
	// 	{
	// 		len1++;
	// 		p1 = p1->next;
	// 	}
	// 	while(p2)
	// 	{
	// 		len2++;
	// 		p2 = p2->next;
	// 	}

	// 	p1 = pHead1, p2 = pHead2;
	// 	if(len1 > len2)
	// 	{
	// 		while(len1 != len2)
	// 		{
	// 			p1 = p1->next;
	// 			-- len1;
	// 		}
	// 	}
	// 	if(len2 > len1)
	// 	{
	// 		while(len1 != len2)
	// 		{
	// 			p2 = p2->next;
	// 			-- len2;
	// 		}
	// 	}

	// 	while(p1 != p2)
	// 	{
	// 		p1 = p1->next;
	// 		p2 = p2->next;
	// 	}

	// 	return p1;
        
    }
};