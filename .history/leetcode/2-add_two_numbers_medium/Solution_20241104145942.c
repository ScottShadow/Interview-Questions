// https://leetcode.com/problems/add-two-numbers/
#include "addTwoNumbers.h"
/* struct ListNode
{
    int val;
    struct ListNode *next;
}; */

/**
 * Adds two non-negative numbers represented as linked lists and returns the
 * result as a linked list. The linked lists are stored in reverse order, and
 * each node contains a single digit. The function assumes that the two numbers
 * do not contain any leading zero, except the number 0 itself.
 *
 * @param l1 The head of the first linked list.
 * @param l2 The head of the second linked list.
 *
 * @return The head of the linked list representing the sum of l1 and l2.
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

    return (head);
}
