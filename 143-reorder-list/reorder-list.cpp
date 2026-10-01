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
    void reorderList(ListNode* head) {
        ListNode* slow;
        ListNode* fast;
         
        slow = head;
        fast = head;
        while(fast != NULL and fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        /*code2*/
        
        ListNode *f = slow;
        ListNode *l = tail;
        
        ListNode* prev = head;
        if(f == head)
        {
          return;
        }
        else
        {
            while(prev->next != f)
            {
                prev = prev->next;
            }
        }
        ListNode *p = l->next;
        ListNode *tem = prev;
        ListNode *curr = prev;
        ListNode *nex = f;
        while(nex != p)
        {
            curr = nex;
            nex = nex->next;
            curr->next = prev;
            prev = curr;
        }
        if(tem != NULL)
        {
            tem->next = l;
            f->next = nex;
        }
        else
        {
            head = l;
            f->next = nex;
        }
        
        ListNode* k;
        ListNode* headA = tem->next;
        tem->next = NULL;
        ListNode *headB = head;
        ListNode* temp = headB;
        ListNode* tempB = headB->next;
        ListNode* tempA = headA;
        int idx = 1;
        k = temp;
        while(tempA != NULL or tempB != NULL)
        {
            if(tempA == NULL)
            {
                break;
            }
            if(idx % 2 == 1)
            {
              temp->next = tempA;
              temp = temp->next;
              tempA = tempA->next;
              }
            if(tempB == NULL)
            {
                break;
            }
            if(idx % 2 == 0)
            {
               temp->next = tempB;
              temp = temp->next;
              tempB = tempB->next;
            }
            idx++;
        }
        head = k;

    }
};