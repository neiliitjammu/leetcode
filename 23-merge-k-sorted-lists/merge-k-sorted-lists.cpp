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
        ListNode *tempA, *tempB, *head, *temp;
        tempA = list1;
        tempB = list2;
        head = NULL;
        temp = head;
        if(tempA == NULL and tempB != NULL)
        {
            return tempB;
        }
        if(tempB == NULL and tempA != NULL)
        {
            return tempA;
        }
        while(tempA != NULL and tempB != NULL)
        {
            if(tempA->val < tempB->val)
            {
                if(temp == NULL)
                {
                    head = tempA;
                    temp = head;
                    tempA = tempA->next;
                    temp->next = NULL;
                }
                else
                {
                    temp->next = tempA;
                    temp = tempA;
                    tempA = tempA->next;
                    temp->next = NULL;
                }
            }
            else 
            {
                if(temp == NULL)
                {
                    head = tempB;
                    temp = head;
                    tempB = tempB->next;
                    temp->next = NULL;
                }
                else
                {
                    temp->next = tempB;
                    temp = tempB;
                    tempB = tempB->next;
                    temp->next = NULL;
                }
            }
        }
        if(tempA == NULL and tempB != NULL)
        {
            while(tempB != NULL)
            {
                temp->next = tempB;
                    temp = tempB;
                    tempB = tempB->next;
                    temp->next = NULL;
            }
        }
        else if(tempA != NULL and tempB == NULL)
        {
            while(tempA != NULL)
            {
                temp->next = tempA;
                    temp = tempA;
                    tempA = tempA->next;
                    temp->next = NULL;
            }
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        {
            return NULL;
        }
        if(lists.size() == 1)
        {
            return lists[0];
        }
        vector<ListNode*> temp;
        int i = 0;
        for(; i < lists.size() - 1; i += 2)
        {
           temp.push_back(mergeTwoLists(lists[i],lists[i+1]));       
        }
        if(i == lists.size() - 1)
        {
            temp.push_back(lists[i]);
        }
        if(temp.size() == 1)
        {
            return temp[0];
        }
        ListNode *head = mergeTwoLists(temp[0],temp[1]) ;
        for(int j = 2; j < temp.size(); j++)
        {
           head = mergeTwoLists(head,temp[j]);          
        }
        return head;
    }
};