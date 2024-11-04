#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function under test
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

// Helper function to create a linked list from an array
struct ListNode *createList(int *arr, int size)
{
    struct ListNode *head = NULL;
    struct ListNode *temp = NULL;
    for (int i = 0; i < size; i++)
    {
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (!head)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Helper function to compare two linked lists
int compareLists(struct ListNode *l1, struct ListNode *l2)
{
    while (l1 && l2)
    {
        if (l1->val != l2->val)
            return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == NULL && l2 == NULL); // Both should reach NULL at the same time
}

// Helper function to free linked list memory
void freeList(struct ListNode *head)
{
    while (head)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

// Struct to hold a single test case
struct TestCase
{
    int *list1;
    int size1;
    int *list2;
    int size2;
    int *expected;
    int expectedSize;
};

// Unit test function
void testAddTwoNumbers(struct TestCase test)
{
    struct ListNode *l1 = createList(test.list1, test.size1);
    struct ListNode *l2 = createList(test.list2, test.size2);
    struct ListNode *expected = createList(test.expected, test.expectedSize);

    struct ListNode *result = addTwoNumbers(l1, l2);
    assert(compareLists(result, expected) && "Test failed");

    freeList(l1);
    freeList(l2);
    freeList(expected);
    freeList(result);
    printf("Test passed!\n");
}

int main()
{
    // Define test cases
    struct TestCase tests[] = {
        // Test case 1: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
        {(int[]){2, 4, 3}, 3, (int[]){5, 6, 4}, 3, (int[]){7, 0, 8}, 3},

        // Test case 2: (9 -> 9) + (1) = 0 -> 0 -> 1
        {(int[]){9, 9}, 2, (int[]){1}, 1, (int[]){0, 0, 1}, 3},

        // Test case 3: (0) + (0) = 0
        {(int[]){0}, 1, (int[]){0}, 1, (int[]){0}, 1},

        // Additional test cases...
    };

    // Run test cases
    int numTests = sizeof(tests) / sizeof(struct TestCase);
    for (int i = 0; i < numTests; i++)
    {
        testAddTwoNumbers(tests[i]);
    }

    return 0;
}
