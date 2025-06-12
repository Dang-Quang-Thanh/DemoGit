#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = head;
    struct ListNode* prev = NULL;
    while(p != NULL && p->next != NULL) {
        if(p->val == val) {
            prev->next = p;
            p->next = prev->next;
        }
    }
    return head;
}
//add a comment
