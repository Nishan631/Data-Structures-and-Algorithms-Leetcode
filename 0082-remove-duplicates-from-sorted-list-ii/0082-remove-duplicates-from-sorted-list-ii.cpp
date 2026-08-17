/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        int prev_val = 101;

        while (head != NULL &&
               (head->val == prev_val ||
                (head->next != NULL && head->val == head->next->val))) {

            ListNode* dup = head;
            head = head->next;
            prev_val = dup->val;
            delete dup;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {

            if (curr->val == prev_val ||
                (curr->next != NULL && curr->val == curr->next->val)) {

                ListNode* dup = curr;
                curr = curr->next;
                prev->next = curr;
                prev_val = dup->val;
                delete dup;
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};