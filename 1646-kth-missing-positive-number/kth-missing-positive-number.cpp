class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 1;
        int num = 0;
        int i = 0;
        while(i < arr.size())
        {
           while(j != arr[i])
           {num++;
           if(num == k)
            {
                return j;
            }
            j++;
           }
           i++;
           j++;
        }
        num++;
        while(num != k)
        {
            j++;
            num++;
        }
        return j;
    }
};