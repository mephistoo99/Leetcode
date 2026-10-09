#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

/*use Floyds cycle finding algorithm*/

bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast->next && slow->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return(true);
    }
    return false;




}