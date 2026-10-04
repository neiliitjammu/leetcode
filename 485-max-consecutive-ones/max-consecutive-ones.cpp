class Solution {
public:

int maxi(vector<int> &arr) {
        int max= INT_MIN;
        for(int i = 0 ; i < arr.size(); i++)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> count;
        int Count = 0;
        int i = 0;
        while(i < nums.size())
        {
            int j = i;
            int Count = 0;
            while(j < nums.size() and nums[j] != 0)
            {
              Count++;
              j++;
            }
            
            count.push_back(Count);
            while(j < nums.size() and nums[j] != 1)
            {
               j++;
            }
            i = j;
        }
        return maxi(count);
    }
};