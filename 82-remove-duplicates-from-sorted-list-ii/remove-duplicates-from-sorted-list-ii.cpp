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
        ListNode *temp;
        temp = head;
        while(temp != NULL)
        {   int i = 0;
            while(temp->next != NULL and temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
                i++;
            }
            if(i > 0)
            {
                ListNode* prev = head;
                if(temp == head)
                {
                    head = head->next;
                    temp = head;
                }
                else
                {while(prev->next != temp)
                {
                    prev = prev->next;
                }
                  prev->next = prev->next->next;
                  temp = prev->next;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};