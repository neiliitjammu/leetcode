/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head == NULL)
        {
            return NULL;
        }
        if(head->next == NULL)
        {
            return NULL;
        }
        slow = slow->next;
        int cycle = 0;
        fast = fast->next->next;
        while(fast != NULL and fast->next != NULL)
        {
            if(slow == fast)
            {   cycle++;
                break;
  
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(cycle)
        {
            ListNode* temp = head;
            while(temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
        return NULL;
    }
};