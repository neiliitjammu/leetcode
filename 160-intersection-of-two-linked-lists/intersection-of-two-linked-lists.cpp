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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = 0;
        ListNode *tempA = headA;
        while(tempA != NULL)
        {
            tempA = tempA->next;
            lA++;
        }
        int lB = 0;
        ListNode *tempB = headB;
        while(tempB != NULL)
        {
            tempB = tempB->next;
            lB++;
        }
        int shift = 0;
        tempA = headA;
        tempB = headB;
        if(lB > lA)
        {
            shift = lB - lA;
            int num = 0;
            while(num != shift)
            {
                tempB = tempB->next;
                num++;
            }
        }
        else if(lA > lB)
        {
            shift = lA - lB;
            int num = 0;
            while(num != shift)
            {
                tempA = tempA->next;
                num++;
            }
        }
        while(tempA != NULL and tempB != NULL and tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};