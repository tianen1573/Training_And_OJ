//反转部分单向链表
//https://www.nowcoder.com/questionTerminal/f11155006f154419b0bef6de8918aea2?answerType=1&f=discussion
list_node * reverse_list(list_node * head, int L, int R)
{
    list_node* begin, *end, *cur, *prev = nullptr;
    cur = head;
    int pos = 1;
    
    //左闭右开
    //begin：反转部分的第一个节点，end：反转部分最后一个节点的next节点
    //prev：begin的父节点， Pcur：最后一个反转节点
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
    
    //链接反转后的尾节点
    begin->next = end;
    
    //若反转了头节点，则反转后的节点为新的头节点
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