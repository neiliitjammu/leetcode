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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = NULL;
        ListNode* nex = head;
        while(nex != NULL)
        {
            curr = nex;
            nex = nex->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        stack<ListNode*> del;
        head = Reverse(head);
        ListNode* temp = head;
        while(temp != NULL)
        {
            while(!st.empty() and (st.top())->val <= temp->val)
            {
               st.pop();
            }
            if(!st.empty())
            {
               del.push(temp);
            }
            st.push(temp);
            temp = temp->next;
        }
    head = Reverse(head);
    temp = head;
    ListNode *p;
    while(temp != NULL and !del.empty())
    {
        
        if(head == del.top())
        {   
            head = head->next;
            temp = head;
        }
        else if(temp == del.top())
        {
            p = head;
            while(p->next != temp)
            {
                p = p->next;
            }
            p->next = p->next->next;
        }
        else
        {
            while(temp->next != del.top())
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        temp = del.top()->next;
        del.pop();
    }
    
    return head;}
};