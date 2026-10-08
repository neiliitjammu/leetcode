class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0;
        int j = k - 1;
        int num = 0;
        int sum = 0;
        for(int i = 0; i <= j; i++)
        {
            sum += arr[i];
        }
        if(sum/k >= threshold)
        {
            num++;
        }
        
        while(j < arr.size())
        {
           i++;
           j++;
           if(j < arr.size())
           {
            sum = sum - arr[i - 1] + arr[j];
           }
           else
           {
            break;
           }
           if(sum/k >= threshold)
           {
            num++;
           }

        }
        return num;
    }
};