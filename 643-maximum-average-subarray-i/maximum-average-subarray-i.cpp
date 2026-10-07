class Solution {
public:
    double findMaxAverage(vector<int>& nums, double k) {
        double sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum += (double)nums[i];
        }
        int j = k - 1;
        int i = 0;
        double maxsum = sum;
        while(j < nums.size() - 1)
        {
            i++;
            j++;
            sum = sum + (double)(nums[j] - nums[i - 1]);
            maxsum = max(sum,maxsum);
        }
       
        return maxsum/k;
    }
};