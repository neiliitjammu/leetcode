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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* headA = NULL;
        ListNode* headB = NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(temp != NULL)
        {
            if(temp->val < x)
            {
                if(headA == NULL)
                {
                    headA = temp;
                    tempA = headA;
                    temp = temp->next;
                    headA->next = NULL;
                }
                else
            {   tempA->next = temp;
                tempA = temp;
                temp = temp->next;
                tempA->next = NULL;
            }
            }
            else
            {
                 if(headB == NULL)
                {
                    headB = temp;
                    tempB = headB;
                    temp = temp->next;
                    headB->next = NULL;
                }
                else
            {   tempB->next = temp;
                tempB = temp;
                temp = temp->next;
                tempB->next = NULL;
            }
            }
        }
        if(tempA == NULL)
        {
            return headB;
        }
        tempA->next = headB;
        return headA;

    }
};