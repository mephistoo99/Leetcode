#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *head;
    struct ListNode *sec;
    struct ListNode *temp;
    struct ListNode *ret;
    if (!list1) return list2;
    if (!list2) return list1;

    if(list2->val > list1->val){
        ret = list1;
        head = list1;
        sec = list2;
    }
    else{
        head = list2;
        ret = list2;
        sec = list1;
    }
    while(head->next && sec){
        if(head->next->val > sec->val){
            temp = sec;
            sec = sec->next;
            temp->next = head->next;
            head->next = temp;
        }
        head = head->next;
    }
    if(!head->next && sec){
        head->next = sec;
    }
    return (ret);
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    int count = 0;
    struct ListNode* hd;
    
    
    if(listsSize == 0 || lists == NULL)
        return NULL;
    hd = lists[0];
    while(count < listsSize-1)
    {
        hd = mergeTwoLists(hd,lists[count+1]);
        count++;
    }
    return (hd);

}

