class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
    vector<int> n;
    int i = 0;
    while(i < nums.size())
    {
       int count = 1;
       int j = i;
       while(j < nums.size() - 1 and nums[j] == nums[j+1])
       {
        count++;
        j++;
       }
       if(count > (nums.size()/3))
       {
        n.push_back(nums[i]);
       }
       if(j == i)
       {
        i++;
       }
       else if(j == nums.size() - 1 and nums[j - 1] == nums[j])
       {
        break;
       }
       else
       {
        i = j;
       }
    }
    return n;
       
    }
};