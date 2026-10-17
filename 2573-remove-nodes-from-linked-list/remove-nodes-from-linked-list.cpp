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
            if(st.empty())
            {
               del.push(temp);
            }
            st.push(temp);
            temp = temp->next;
        }
    head = del.top();
    temp = head;
    temp->next = NULL;
    del.pop();
    while(!del.empty())
    {
        temp->next = del.top();
        temp = temp->next;
        temp->next = NULL;
        del.pop();
    }
   
    return head;}
};