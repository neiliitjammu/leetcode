class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        stack<int> st;
        
        vector<int> ans(arr.size(),0);
        
        for(int i = arr.size() - 1; i >= 0; i--)
        {
          while(!st.empty() and arr[st.top()] <= arr[i])
          {
              st.pop();
              ans[i]++;
          }
          if(!st.empty())
          {
              ans[i]++;
          }
          st.push(i);
        }
     
       return ans;
    }
};