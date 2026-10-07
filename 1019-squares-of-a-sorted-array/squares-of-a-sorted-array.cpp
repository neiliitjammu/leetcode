class Solution {
public:
    vector<int> sq(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i];
        }
        return nums;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int j = 0;
        int i = 0;
        if(nums.size() == 0)
        {
            return nums;
        }
        if(nums.size() == 1)
        {
            return sq(nums);
        }
        while(i < nums.size() and nums[i] <= 0)
        {
            i++;
        }
        if(i == 0)
        {
            return sq(nums);
        }
        else if(i == nums.size())
        {
            nums = sq(nums);
            reverse(nums.begin(),nums.end());
            return nums;
        }
        else
        {
            j = i - 1;
            nums = sq(nums);
            reverse(nums.begin(),nums.begin() + j + 1);
            vector<int> neil;
            int a = 0;
            int b = j + 1;
            while(a <= j and b < nums.size())
            {
                if(nums[a] > nums[b])
                {
                    neil.push_back(nums[b]);
                    b++;
                }
                else
                {
                    neil.push_back(nums[a]);
                    a++;
                }
            }
            if(a <= j and b >= nums.size())
            {
                while(a <= j)
                {
                    neil.push_back(nums[a]);
                    a++;
                }
            }
            if(a > j and b < nums.size())
            {
                while(b < nums.size())
                {
                    neil.push_back(nums[b]);
                    b++;
                }
            }
        return neil;
        }
    }
};