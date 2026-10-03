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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* tempA = l1;
       ListNode* tempB = l2;
       ListNode* head = NULL;
       ListNode* temp = NULL;
       int carry = 0;
       while(tempA != NULL and tempB != NULL)
       {
        if(tempA->val + tempB->val + carry > 9)
        {
            ListNode* newnode = new ListNode((tempA->val + tempB->val + carry) % 10);
         carry = 1;
         
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;}

        }
        else
        {   
            ListNode* newnode = new ListNode(tempA->val + tempB->val + carry);
            carry = 0;
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;
          }
        }
        tempA = tempA->next;
          tempB = tempB->next;
       }

       if(tempA == NULL and tempB != NULL)
       {
        while(tempB != NULL)
        {
        if(tempB->val + carry > 9)
        {
            ListNode* newnode = new ListNode((tempB->val + carry) % 10);
         carry = 1;
         
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;}
        }
        else
        {
            ListNode* newnode = new ListNode(tempB->val + carry);
            carry = 0;
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;
          }
        }
        tempB = tempB->next;
        }
        if(carry != 0)
        {
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
            temp = temp->next;
        }
       }


       else if(tempB == NULL and tempA != NULL)
       {
        while(tempA != NULL)
        {
        if(tempA->val + carry > 9)
        {
            ListNode* newnode = new ListNode((tempA->val + carry) % 10);
         carry = 1;
         
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;}
        }
        else
        {
            ListNode* newnode = new ListNode(tempA->val + carry);
            carry = 0;
          if(temp == NULL)
          {
            temp = newnode;
            head = temp;
          }
          else
          {
            temp->next = newnode;
            temp = temp->next;
          }
        }
        tempA = tempA->next;
        }
        if(carry != 0)
        {
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
            temp = temp->next;
        }
       }
       else
       {
        if(carry != 0)
        {
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
            temp = temp->next;
        }
       }
       return head;
    }
};