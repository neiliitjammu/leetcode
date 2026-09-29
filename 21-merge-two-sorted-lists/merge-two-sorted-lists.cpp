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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *i = list1;
        ListNode *j = list2;
        ListNode *head = NULL;
        ListNode *temp = head;
        while(j != NULL and i != NULL)
        {
            if(i->val < j->val)
            {
                if(head == NULL)
                {
                    head = i;
                    temp = head;
                }
                 else
                 {
                    temp->next = i;
                    temp = temp->next;
                 }
                 i = i->next;
            }
            else
            {
                if(head == NULL)
                {
                    head = j;
                    temp = head;
                }
                 else
                 {
                    temp->next = j;
                    temp = temp->next;
                 }
                 j = j->next;
            }
        }
        if(j == NULL)
        {
            while(i != NULL)
            {
                if(temp == NULL)
                {
                    temp = i;
                    head = i;
                    i = i->next;
                }
                else
                {temp->next = i;
                    temp = temp->next;
                    i = i->next;}
            }
        }
        if(i == NULL)
        {
            while(j != NULL)
            {   if(temp == NULL)
            {
                temp = j;
                head = j;
                j = j->next;
            }
                else
                {temp->next = j;
                    temp = temp->next;
                    j = j->next;}
            }
        }
        return head;
        
    }
};