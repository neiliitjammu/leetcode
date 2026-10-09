class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lastneg = -1;
        int firstneg = -1;
        int low = 0;
        int mid;
        int high = nums.size() - 1;
           while(low <= high)
           {
            mid = (low + high)/2;
            if(nums[mid] < 0)
            {
                lastneg = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
           }
           
           low = 0;
      
        high = nums.size() - 1;
           while(low <= high)
           {
            mid = (low + high)/2;
            if(nums[mid] < 0)
            {
                firstneg = mid;
                high = mid - 1;
            }
            else
            {
                high = mid - 1;
            }
           }

           int neg = (lastneg-firstneg) + 1;
           if(lastneg == firstneg and lastneg == -1)
           {
             neg = 0;
           }


           int lastpos = -1;
        int firstpos = -1;
        low = 0;
        
         high = nums.size() - 1;
           while(low <= high)
           {
            mid = (low + high)/2;
            if(nums[mid] > 0)
            {
                lastpos = mid;
                low = mid + 1;
            }
            else
            {
                low = mid + 1;
            }
           }
           
           low = 0;
      
        high = nums.size() - 1;
           while(low <= high)
           {
            mid = (low + high)/2;
            if(nums[mid] > 0)
            {
                firstpos = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
           }
           int pos = (lastpos-firstpos) + 1;
           if(lastpos == firstpos and lastpos == -1)
           {
             pos = 0;
           }
           return max(neg,pos);

    }
};