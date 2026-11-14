class Solution {
public:
    // Reverse a linked list iteratively
    ListNode* reverse(ListNode* head) {
        ListNode* node = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }

        return node;
    }

    // Find the Kth node from the current starting node
    ListNode* getK(ListNode* temp, int k) {
        k = k - 1;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* KthNode = getK(temp, k);

            // Fewer than k nodes remain
            if (KthNode == NULL) {
                if (prev) prev->next = temp;
                break;
            }

            // Store the next group's starting node
            ListNode* newnode = KthNode->next;

            // Disconnect and reverse the current group
            KthNode->next = NULL;
            reverse(temp);

            // Connect the reversed group
            if (temp == head) {
                head = KthNode;
            } else {
                prev->next = KthNode;
            }

            // Original group's first node becomes its tail
            prev = temp;
            temp = newnode;
        }

        return head;
    }
};