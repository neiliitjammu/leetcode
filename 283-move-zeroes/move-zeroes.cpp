class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size() - 1; j++ )
            {
                if(nums[j] == 0 and nums[j + 1] != 0)
                {
                   swap(nums[j+1],nums[j]);
                }
            }
        }
    }
};