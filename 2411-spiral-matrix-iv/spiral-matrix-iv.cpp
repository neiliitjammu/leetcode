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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n));
        int i = 0; 
        int il = m - 1;
        int j = 0;
        int jl = n - 1;
        ListNode *temp = head;
        while(i <= il and j <= jl)
        {
            for(int m = j; m <= jl; m++)
            {  if(temp != NULL)
               {mat[i][m] = temp->val;
               temp = temp->next;
               }
               else
               {
                mat[i][m] = -1;
               }
               
            }
            i++;
            if(i > il or j > jl)
            {
                break;
            }
             for(int m = i; m <= il; m++)
            {  if(temp != NULL)
               {mat[m][jl] = temp->val;
               temp = temp->next;
               }
               else
               {
                mat[m][jl] = -1;
               }
               
            }
            jl--;
            if(i > il or j > jl)
            {
                break;
            }
            for(int m = jl; m >= j; m--)
            {  if(temp != NULL)
               {mat[il][m] = temp->val;
               temp = temp->next;
               }
               else
               {
                mat[il][m] = -1;
               }
               
            }
            il--;
            if(i > il or j > jl)
            {
                break;
            }
            for(int m = il; m >= i; m--)
            {  if(temp != NULL)
               {mat[m][j] = temp->val;
               temp = temp->next;
               }
               else
               {
                mat[m][j] = -1;
               }
               
            }
            j++;
            if(i > il or j > jl)
            {
                break;
            }
        }
        return mat;
    }
};