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

   ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *temp1, *temp2, *newnode, *head, *temp;
        temp1 = list1;
        temp2 = list2;
        head = NULL;
        int j = 0;
        int k = 0;
        while(temp1 != NULL or temp2 != NULL)
        {
          j++;
          if(j == 1)
          {
            if(temp1 != NULL and temp2 != NULL)
            {
                if(temp1->val >= temp2->val)
                {
                    k = temp2->val;
                    temp2 = temp2->next;
                }
                else
                {
                    k = temp1->val;
                     temp1 = temp1->next;
                }
               
                
            }
            else if(temp1 == NULL and temp2 != NULL)
            {
                k = temp2->val;
                temp2 = temp2->next;
            }
            else if(temp1 != NULL and temp2 == NULL)
            {
                k = temp1->val;
                temp1 = temp1->next;
            }
            newnode = new ListNode(k);
            head = newnode;
            temp = newnode;
            temp->next = NULL;
          }
          else
          {
            if(temp1 != NULL and temp2 != NULL)
            {
                if(temp1->val >= temp2->val)
                {
                    k = temp2->val;
                     temp2 = temp2->next;
                }
                else
                {
                    k = temp1->val;
                    temp1 = temp1->next;
                }
                
               
            }
            else if(temp1 == NULL and temp2 != NULL)
            {
                k = temp2->val;
                temp2 = temp2->next;
            }
            else if(temp1 != NULL and temp2 == NULL)
            {
                k = temp1->val;
                temp1 = temp1->next;
            }
            newnode = new ListNode(k);
            temp->next = newnode;
            temp = newnode;
            temp->next = NULL;
          }
         
        }
         return head;
    }

    ListNode* mergesort(ListNode *i)
    {
        if(i != NULL and i->next != NULL)
        {
            ListNode *slow = i;
            ListNode *fast = i;
            while(fast->next != NULL and fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            ListNode* temp = slow->next;
             slow->next = NULL;
            i = mergesort(i);
             temp = mergesort(temp);
             ListNode* head;

             head = merge(i,temp);
             return head;
        }
        return i;
    }


    ListNode* sortList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        head = mergesort(head);
        return head;
    }
};