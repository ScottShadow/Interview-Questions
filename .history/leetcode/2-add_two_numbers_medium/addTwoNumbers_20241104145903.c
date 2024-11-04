#include "addTwoNumbers.h"
#include <assert.h>
/**
 * Helper function to create a linked list from an array.
 *
 * @param arr The array of integer values to create the linked list from.
 * @param size The size of the array.
 *
 * @return The head node of the linked list.
 */
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

/**
 * Helper function to compare two linked lists.
 *
 * This function iterates through both linked lists and compares the values
 * of the nodes. If all corresponding nodes have the same value and both
 * lists reach the end (NULL) simultaneously, the lists are considered equal.
 *
 * @param l1 The head of the first linked list.
 * @param l2 The head of the second linked list.
 *
 * @return 1 if the linked lists are equal, 0 otherwise.
 */
int compareLists(struct ListNode *l1, struct ListNode *l2)
{
    // Traverse both lists until one of them ends
    while (l1 && l2)
    {
        // If values differ, lists are not equal
        if (l1->val != l2->val)
            return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    // Both lists should reach the end (NULL) at the same time
    return (l1 == NULL && l2 == NULL);
}

/**
 * Helper function to free the memory allocated for a linked list.
 *
 * This function iterates through the linked list and frees the memory
 * allocated for each node. It is important to call this function to
 * avoid memory leaks after the linked list is no longer needed.
 *
 * @param head The head of the linked list to be freed.
 */
void freeList(struct ListNode *head)
{
    while (head)
    {
        struct ListNode *temp = head; // Store the current node
        head = head->next;            // Move to the next node
        free(temp);                   // Free the memory of the current node
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

/**
 * Runs a test case for the addTwoNumbers function.
 *
 * This function creates the linked lists for the two input numbers
 * and the expected result, and then calls the addTwoNumbers function
 * to check if the result matches the expected result.
 *
 * @param test The test case to be run.
 */
void testAddTwoNumbers(struct TestCase test)
{
    // Create the linked lists for the input numbers and the expected result
    struct ListNode *l1 = createList(test.list1, test.size1);
    struct ListNode *l2 = createList(test.list2, test.size2);
    struct ListNode *expected = createList(test.expected, test.expectedSize);

    // Call the addTwoNumbers function and check the result
    struct ListNode *result = addTwoNumbers(l1, l2);
    assert(compareLists(result, expected) && "Test failed");

    // Free the memory allocated for the linked lists
    freeList(l1);
    freeList(l2);
    freeList(expected);
    freeList(result);

    printf("Test passed!\n");
}

/**
 * The main function that executes the test cases for the addTwoNumbers function.
 *
 * This function defines an array of test cases, each of which contains two input
 * linked lists representing numbers, and the expected linked list result. It then
 * iterates through each test case, calling the testAddTwoNumbers function to
 * verify the correctness of the addTwoNumbers function implementation. If all
 * test cases pass, the function returns 0.
 */
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
