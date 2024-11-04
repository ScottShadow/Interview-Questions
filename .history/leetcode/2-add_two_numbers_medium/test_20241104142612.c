#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function under test
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

// Helper function to compare two linked lists
int compareLists(struct ListNode* l1, struct ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == NULL && l2 == NULL); // Both should reach NULL at the same time
}

// Helper function to free linked list memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Unit test for addTwoNumbers
void testAddTwoNumbers() {
    // Test case 1: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int expectedArr[] = {7, 0, 8};
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);
    struct ListNode* expected = createList(expectedArr, 3);

    struct ListNode* result = addTwoNumbers(l1, l2);

    // Check if the result matches the expected output
    assert(compareLists(result, expected) && "Test case 1 failed");

    // Free all lists
    freeList(l1);
    freeList(l2);
    freeList(expected);
    freeList(result);

    printf("Test case 1 passed!\n");

    // Additional test cases can be added in the same format
}

int main() {
    testAddTwoNumbers();
    return 0;
}
