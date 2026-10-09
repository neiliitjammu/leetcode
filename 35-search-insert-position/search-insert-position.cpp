class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
                int high = nums.size() - 1;
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
 
          if(ans == -1)
          {
              return high + 1;
          }
          else
          {
              return ans;
          }
    }
};