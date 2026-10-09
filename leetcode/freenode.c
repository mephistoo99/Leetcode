
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
static int ft_lstsize(struct ListNode* lst)
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    int c =1;
    int size = ft_lstsize(head);
    struct ListNode* link;
    struct ListNode* head2 = head;
    
    if(size==1 && n == 1){
        free(head);
        head = NULL;
        return (head);
    }
    if(size==1 && n != 1){
        return (head);
    }

    if(n>size){
        return (head);
    }
    if(n==size)
    {
        while(head2->next && n - 1 > c)
        {
            head2 = head2->next;
            c++;
        }
        free(head2->next);
        head2->next = NULL;
        return (head);

    }
    
    if(n == 1)
    {
        head = head->next;
        free(head2);
        return (head);

    }
    while(head2->next && n - 1 > c)
    {
        head2 = head2->next;
        c++;
    }
    link = head2->next->next;
    free(head2->next);
    head2->next =link;
    return (head) ;  
}
