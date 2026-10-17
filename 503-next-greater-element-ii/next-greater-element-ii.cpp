class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int> st;
                       vector<int> ans;
                   
                      
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
                             int p;
                            for(p = 0; p <= k; p++)
                            {
                                if(nums[p] > nums[i])
                                {
                                    break;
                                }
                            }
                            if(p <= k)
                            {
                                ans.push_back(nums[p]);
                            }
                            else
                            {
                                ans.push_back(-1);
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