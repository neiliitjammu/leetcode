class Solution {
public:
    bool isPerfectSquare(long long num) {
        long long low = 1;
           long long high = num;
           
           long long mid;
           while(low <= high)
           {   mid = low + ((high - low)/2);
                if(mid*mid > num)
                {
                   
                    high = mid - 1;
                }
                else if(mid*mid == num)
                {
                    return true;
                }
                else
                {
                    low = mid + 1;
                }
           }
           return false;
    }
};