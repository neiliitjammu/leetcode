class Solution {
public:
    int mySqrt(int x) {
           int low = 1;
           int high = x;
           int root = -1;
           if(x == 0)
           {
            return 0;
           }
           int mid;
           while(low <= high)
           {   mid = low + ((high - low)/2);
                if(mid > x/mid)
                {
                    root = mid;
                    high = mid - 1;
                }
                else if(mid == x/mid)
                {
                    return mid;
                }
                else
                {
                    low = mid + 1;
                }
           }
           return root - 1;
    }
};