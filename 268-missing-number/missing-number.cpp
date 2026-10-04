class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> flag(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++)
        {
            flag[nums[i]] = 1;
        }
        for(int i = 0; i < flag.size(); i++)
        {
            if(flag[i] == 0)
            {
                return i;
            }
        }
        return 0;
    }
};