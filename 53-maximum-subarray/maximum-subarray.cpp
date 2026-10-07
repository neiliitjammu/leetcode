class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = 0;
        int maxsum = nums[0];
        int ele = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            ele = nums[i];
            current += nums[i];
            current = max(current,ele);
            maxsum = max(current,maxsum);
        }
        return maxsum;
    }
};