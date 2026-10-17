class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int> st;
                       vector<int> ans;
                       stack<int> sti;
                      
                       for(int i = nums.size() - 1; i >= 0; i--)
                       {
                         while(!st.empty() and st.top() <= nums[i])
                         {
                             st.pop();
                         }
                         //search in other stack
                         if(st.empty())
                         {
                             int k = i - 1;
                             if(k < 0)
                             {  ans.push_back(-1);
                                break;
                             }
                             while(k >= 0)
                             {
                                  if(nums[k] > nums[i])
                                  {
                                    sti.push(nums[k]);
                                    
                                  }
                                  k--;
                             }
                             if(sti.empty())
                             {
                                ans.push_back(-1);
                             }
                             else
                             {
                                ans.push_back(sti.top());
                             }
                             while(!sti.empty())
                             {
                                sti.pop();
                             }
                         }
                         //else case scenario
                         else
                         {
                             ans.push_back(st.top());
                         }
                         st.push(nums[i]);
                       }
                       reverse(ans.begin(),ans.end());
                      return ans;
    }
};