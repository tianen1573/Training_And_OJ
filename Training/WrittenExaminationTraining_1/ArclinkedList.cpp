//��ת���ֵ�������
//https://www.nowcoder.com/questionTerminal/f11155006f154419b0bef6de8918aea2?answerType=1&f=discussion
list_node * reverse_list(list_node * head, int L, int R)
{
    list_node* begin, *end, *cur, *prev = nullptr;
    cur = head;
    int pos = 1;
    
    //����ҿ�
    //begin����ת���ֵĵ�һ���ڵ㣬end����ת�������һ���ڵ��next�ڵ�
    //prev��begin�ĸ��ڵ㣬 Pcur�����һ����ת�ڵ�
    while(pos < L)
    {
        prev = cur;
        cur = cur->next;
        ++ pos;
    }
    begin = cur;
    while(pos <= R)
    {
        cur = cur->next;
        ++ pos;
    }
    end = cur;
    
    list_node* Pcur = begin;
    cur = begin->next;
    while(cur != end)
    {
        list_node* next = cur->next;
        cur->next = Pcur;
        Pcur = cur;
        cur = next;
    }
    
    //���ӷ�ת���β�ڵ�
    begin->next = end;
    
    //����ת��ͷ�ڵ㣬��ת��Ľڵ�Ϊ�µ�ͷ�ڵ�
    if(prev == nullptr)
    {
        return Pcur;
    }
    else
    {
        prev->next = Pcur;
        return head; 
    }
      
}