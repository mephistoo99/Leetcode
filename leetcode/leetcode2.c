#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!newNode) return NULL;
        newNode->val = sum % 10;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            curr = newNode;
        } else {
            curr->next = newNode;
            curr = newNode;
        }
    }
    return head;
}
