#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

/*used Floyd's cycle finding algorithm*/

bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast && fast->next))
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return(true);
    }
    return false;
}
