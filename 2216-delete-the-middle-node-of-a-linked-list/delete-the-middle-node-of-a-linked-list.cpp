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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* tortoise;
        ListNode* hare;
        if(head->next == NULL)
        {
            return NULL;
        }
        tortoise = head;
        hare = head;
        while(hare != NULL and hare->next != NULL)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        ListNode* temp;
        temp = head;
        while(temp->next != tortoise)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete tortoise;
        return head;
    }
};