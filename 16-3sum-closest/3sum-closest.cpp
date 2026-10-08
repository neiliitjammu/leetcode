class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int i = 0;
        int j = i + 1;
        int k = nums.size() - 1;
        sort(nums.begin(),nums.end());
        int closest = nums[i] + nums[j] + nums[k];
        while(i < nums.size() - 2)
        {   
            while(j < k)
            { if(abs(target - closest) > abs(target - (nums[i] + nums[j] + nums[k])))
            {
                closest = nums[i] + nums[j] + nums[k];
            }
            
              if(nums[i] + nums[j] + nums[k] == target)
              {
                  return target;
              }
              else if(target - (nums[i] + nums[j] + nums[k]) > 0)
              { 
               j++;
              }
              else
              {
                k--;
              }
            }
            i++;
            j = i + 1;
            k = nums.size() - 1;
        }
        
        return closest;
    }
    }
;