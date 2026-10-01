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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = 1;
        ListNode *f = head;
        while(n != left)
        {
            f = f->next;
            n++;
        }
        n = 1;
        ListNode *l = head;
        while(n != right)
        {
            l = l->next;
            n++;
        }
        ListNode* prev = f;
        ListNode* temp = l->next;
        ListNode *curr = prev;
        ListNode *nex = f->next;
        while(nex != temp)
        {
            curr = nex;
            nex = nex->next;
            curr->next = prev;
            prev = curr;
        }
        if(f == head)
        {
           head = l;
           f->next = nex;
        }
        else
        {
            prev = head;
            while(prev->next != f)
            {
                prev = prev->next;
            }
            prev->next = l;
            f->next = nex;
        }
        return head;
        
    }
};