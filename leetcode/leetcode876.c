#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static int lstsize(struct ListNode *lst)
{
    int count;

    count = 0;
    if(!lst)
        return 0;
    while(lst){
        lst = lst->next;
        count++;
    }
    return (count);
}


struct ListNode* middleNode(struct ListNode* head)
{
    int size = lstsize(head);
    int count = 0;
    size = size/2;
    while (count++ < size)
    {
        head = head->next;
    }
    return head;
}