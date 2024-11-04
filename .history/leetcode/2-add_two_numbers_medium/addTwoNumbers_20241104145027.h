#ifndef ADD_TWO_NUMBERS_H
#define ADD_TWO_NUMBERS_H

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

#endif