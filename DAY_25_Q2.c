#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: find cycle start
            struct ListNode *entry = head;

            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            return entry; // start of cycle
        }
    }

    return NULL; // no cycle
}