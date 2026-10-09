class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        if(nums.size() == 1)
        {
            if(target == nums[low])
            {
                vector<int> ans = {low,low};
                return ans;
            }
            else
            {
                vector<int> ans = {-1,-1};
                return ans;
            }
        }
        int ans = -1;
        int mid = (low + high)/2;
        
        while(low <= high)
        {  mid = (low + high)/2; 
            if(nums[mid] == target)
            {   
                
                ans = mid;
                high = mid - 1;
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
        vector<int> sol;
        sol.push_back(ans);
        low = 0;
        high = nums.size() - 1;
        mid = (low + high)/2;
        ans = -1;
        while(low <= high)
        {  mid = (low + high)/2; 
            if(nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
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
        sol.push_back(ans);
        return sol;
     
    }
};