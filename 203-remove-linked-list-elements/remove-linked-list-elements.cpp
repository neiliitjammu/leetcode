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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
        {
            return NULL;
        }
        ListNode *temp = head;
        while(temp != NULL)
        {
        while(temp != NULL and temp->val != val)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            break;
        }
        if(temp->val == val)
        {
            if(temp == head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
            else
            {
                ListNode *prev = head;
                while(prev->next != temp)
                {
                    prev = prev->next;
                }
                prev->next = prev->next->next;
                delete temp;
                temp = prev->next;
            }
        }
        }
        return head;
    }
};