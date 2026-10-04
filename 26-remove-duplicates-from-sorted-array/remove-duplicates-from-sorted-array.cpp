class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       vector<int> neil;
       int i = 0;
       while(i < nums.size())
       {
            int j = i;
            while(j < nums.size() - 1 and nums[j + 1] == nums[j])
            {
                j++;
            } 
            if(j < nums.size())
            {
                neil.push_back(nums[j]);
            }
            i = j + 1;
       }
       nums = neil;
       return neil.size(); 
    }
};