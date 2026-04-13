class Solution {
public:
    int removeLoop(struct Node* head) {
        struct Node *slow = head, *fast = head;

        // Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Loop found
                slow = head;

                // Find start of loop
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                // Find last node of loop
                struct Node* temp = fast;
                while (temp->next != slow) {
                    temp = temp->next;
                }

                // Break loop
                temp->next = NULL;
                return 1;
            }
        }

        return 1;  // GFG expects true even if no loop
    }
};