
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
static int ft_lstsize(struct ListNode *lst)
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *previous;
    struct ListNode *del;
    int sizeoflist = ft_lstsize(head);
    int count = 1;
    previous = head;
    
    if(n>sizeoflist)
        return (head);
    if(n == sizeoflist)
    {
        head = head->next;
        free(previous);
        return (head);
    }
    while(count < sizeoflist - n)
    {
        previous = previous->next;
        count++;
    }
    del = previous->next;
    previous->next = del->next;
    free(del);
    return (head);
}
