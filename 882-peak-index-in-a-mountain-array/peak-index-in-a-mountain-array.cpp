class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high)/2;
        while(low <= high)
        {  mid = (low + high)/2; 
            if(mid != 0 and mid != nums.size() - 1 and nums[mid] > nums[mid-1] and nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if(mid != 0 and mid != nums.size() - 1 and nums[mid] > nums[mid-1] and nums[mid] < nums[mid+1])
            {
                low = mid + 1;
            }
            else if(mid == 0 and nums[mid] < nums[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};