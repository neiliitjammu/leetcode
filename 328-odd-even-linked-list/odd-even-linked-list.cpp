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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        int idx = 1;
        ListNode* headA = NULL;
        ListNode* headB = NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(temp != NULL)
        {
            if(idx % 2 == 1)
            {
                if(headA == NULL)
                {
                    headA = temp;
                    tempA = headA;
                    temp = temp->next;
                    idx++;
                    headA->next = NULL;
                }
                else
            {   tempA->next = temp;
                tempA = temp;
                temp = temp->next;
                idx++;
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
                    idx++;
                    headB->next = NULL;
                }
                else
            {   tempB->next = temp;
                tempB = temp;
                temp = temp->next;
                idx++;
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