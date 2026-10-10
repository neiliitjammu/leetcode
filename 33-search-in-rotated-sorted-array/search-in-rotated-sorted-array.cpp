class Solution {
public:

    int bslow(vector<int>& nums,int low, int target) {
        
        int high = nums.size() - 1;
        if(nums.size() == 1)
        {
            if(target == nums[low])
            {
                return low;
            }
            else
            {
                return -1;
            }
        }
        int mid = (low + high)/2;
        while(low <= high)
        {  mid = (low + high)/2; 
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;

    }
    
    int bshigh(vector<int>& nums,int high, int target) {
        
        int low = 0;
        if(nums.size() == 1)
        {
            if(target == nums[low])
            {
                return low;
            }
            else
            {
                return -1;
            }
        }
        int mid = (low + high)/2;
        while(low <= high)
        {  mid = (low + high)/2; 
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;

    }


    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        int ans = -1;
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        
        if(nums[high] > nums[low])
        {
            return bslow(nums,0,target);
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
        
        if(nums[0] > target)
        {
            return bslow(nums,ans+ 1,target);
        }
        else
        {
            return bshigh(nums,ans,target);
        }
        return -1;
    }
    };
