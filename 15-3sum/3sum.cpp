class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        while(i < nums.size() - 2)
        {   
            while(j < k)
            {
              if(nums[i] + nums[j] + nums[k] == 0)
              {
                  vector<int> p = {nums[i],nums[j],nums[k]};
                  sort(p.begin(),p.end());
                  s.insert(p);
                  j++;
                  k--;
              }
              else if(nums[i] + nums[j] + nums[k] > 0)
              {
                k--;
              }
              else
              {
                j++;
              }
            }
            i++;
            j = i + 1;
            k = nums.size() - 1;
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};