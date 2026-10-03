/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* headA = NULL;
        Node* tempA = headA;
        Node* temp = head;

        while(temp != NULL)
        {   Node* newnode = new Node(temp->val);
            if(tempA == NULL)
            {
                tempA = newnode;
                headA = tempA;
            }
            else
            {
                tempA->next = newnode;
                tempA = tempA->next;
            }
            temp = temp->next;
        }

        temp = head;
        tempA = headA;
        
        while(temp != NULL)
        {
          
          if(temp->random == NULL)
          {
            tempA->random = NULL;
            temp = temp->next;
            tempA = tempA->next;
          }
          else
          { Node* rndm = temp->random;
            Node* a = head;
            int len = 0;
            while(a != rndm)
            {
                a = a->next;
                len++;
            }
            Node* tem = headA;
            int t = 0;
            while(t != len)
            {
                tem = tem->next;
                t++;
            }
            tempA->random = tem;
            temp = temp->next;
            tempA = tempA->next;
          }
        }

        return headA;

    }
};