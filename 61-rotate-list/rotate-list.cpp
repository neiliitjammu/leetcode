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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return head;
        }
        
        ListNode *temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        k = k % length;
        if(k == 0)
        {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int num = 1;
        while(num != k)
        {
            fast = fast->next;
            num++;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *prev = head;
        while(prev->next != slow)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        fast->next = head;
        head = slow;
        return head;
    }
};