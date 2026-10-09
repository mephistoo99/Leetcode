#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
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

struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* head2;
    struct ListNode* temp;
    struct ListNode* prev = NULL;
    int size;

    size = lstsize(head);

    if(head == NULL || size ==1)
        return head;
    
    if(size == 2){
        temp = head->next;
        head->next->next = head;
        head -> next = NULL;
        head = temp;
        return head;
    }
    head2 = head->next;
    
   
    
    
    while(head &&head->next)
    {
        temp = head->next; 
        head->next = temp->next; 
        temp->next = head;
        
        if(prev){
            prev->next = temp;
        }
        prev = head;
        head = head ->next;

    }
    
    return head2;


}
