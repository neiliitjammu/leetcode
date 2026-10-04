class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                n.push_back(nums[i]);
            }
            else
            {
                p.push_back(nums[i]);
            }
        }
        vector<int> arr;
        
        int j = 0;
        while(j < p.size())
        {
            arr.push_back(p[j]);
            arr.push_back(n[j]);
            j++;
        }
        return arr;
    }
};