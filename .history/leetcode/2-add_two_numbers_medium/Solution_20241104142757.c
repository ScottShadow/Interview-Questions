#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *AnswerNode = malloc(sizeof(struct ListNode));
    struct ListNode *head = AnswerNode;
    int carryover = 0;

    while (l1 || l2 || carryover)
    {
        int val1 = (l1) ? l1->val : 0;
        int val2 = (l2) ? l2->val : 0;
        AnswerNode->val = val1 + val2 + carryover;
        carryover = 0;
        if (AnswerNode->val > 9)
        {
            carryover = AnswerNode->val / 10;
            AnswerNode->val = AnswerNode->val % 10;
        }
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
        if (l1 || l2 || carryover)
        {
            AnswerNode->next = malloc(sizeof(struct ListNode));
            AnswerNode = AnswerNode->next;
            AnswerNode->next = NULL;
        }
        else
        {
            AnswerNode->next = NULL;
        }
    }

    return head;
}
