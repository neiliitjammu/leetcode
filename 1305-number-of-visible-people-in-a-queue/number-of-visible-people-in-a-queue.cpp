class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        stack<int> st;
        
        vector<int> ans;
        for(int i = arr.size() - 1; i >= 0; i--)
        {
          while(!st.empty() and arr[st.top()] <= arr[i])
          {
              st.pop();
          }
          if(st.empty())
          {
              ans.push_back(-1);
          }
          else
          {
              ans.push_back(st.top());
          }
          st.push(i);
        }
      reverse(ans.begin(),ans.end());
         vector<int> sol;
         int val;
         for(int i = 0; i < ans.size(); i++)
         {
            val = 1;
            int j = i + 1;
            if(j == ans.size())
            {
                sol.push_back(0);
                break;
            }

            while((j < ans.size()) and (ans[j] != -1) and (arr[i] > arr[j]))
            {
                j = ans[j];
                val++;
            }
            sol.push_back(val);
         }
         return sol;
               
             }
};