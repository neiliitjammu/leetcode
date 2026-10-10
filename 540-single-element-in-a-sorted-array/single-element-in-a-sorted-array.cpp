class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if(nums.size() == 1)
        {
            return nums[0];
        }
        if(nums[low] != nums[low+1])
        {
            return nums[low];
        }
       
        if(nums[high] != nums[high - 1])
        {
            return nums[high];
        }
      
        int mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(nums[mid - 1] != nums[mid] and nums[mid+1] != nums[mid])
            {
                return nums[mid];
            }
            else if(nums[mid - 1] == nums[mid] and (mid - low + 1) % 2 == 0)
            {
                low = mid + 1;
            }
            else if(nums[mid - 1] == nums[mid] and (mid - low + 1) % 2 == 1)
            {
                high = mid - 1;
            }
            else if(nums[mid + 1] == nums[mid] and (mid - low + 1) % 2 == 0)
            {
                  high = mid - 1;
            }
            else if(nums[mid + 1] == nums[mid] and (mid - low + 1) % 2 == 1)
            {
                low = mid + 2;
            }
        }
        return -1;
    }
};