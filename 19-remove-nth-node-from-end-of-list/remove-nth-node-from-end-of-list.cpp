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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        int k = 1;
        while(k != n)
        {
            fast = fast->next;
            k++;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *prev = head;
        if(slow == head)
        {
            head = head->next;
            delete slow;
            return head;
        }
        while(prev->next != slow)
        {
            prev = prev->next;
        }
        prev->next = prev->next->next;
        delete slow;
        return head;
    }
};