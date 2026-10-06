class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i >= 0)
        {
            while(i > 0 and nums[i - 1] >= nums[i])
            {
                i--;
            }
            if(i == 0)
            {
                sort(nums.begin(),nums.end());
                return;
            }
            else if(i == nums.size() - 1)
            {
                swap(nums[i],nums[i-1]);
                return;
            }
            else
            {
               i--;
               sort(nums.begin() + i + 1, nums.end());
               int j = i + 1;
               while(j < nums.size() and nums[i] >= nums[j])
               {
                j++;
               }
               if(j == nums.size())
               {
                j = nums.size() - 1;
               }
               swap(nums[i],nums[j]);
               sort(nums.begin() + i + 1, nums.end());
            return;
            }
        }

    }
};