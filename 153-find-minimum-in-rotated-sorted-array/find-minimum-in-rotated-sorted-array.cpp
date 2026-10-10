class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        int ans = -1;
        if(nums[high] > nums[low])
        {
            return nums[low];
        }
        
        while(low <= high)
        {
            mid = low + ((high - low)/2);
            if(nums[mid] > nums[0])
            {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] == nums[0])
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return nums[ans + 1];
    }
};