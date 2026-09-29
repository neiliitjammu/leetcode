class Solution {
public:
    int squaresum(int num)
    {
        int sum = 0;
        while(num != 0)
        {
            sum += (num % 10)*(num % 10);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int sum = squaresum(n);
        if(sum == 1)
        {
            return true;
        }
        while(sum != 1)
        {
            if(sum == 4)
            {
                return false;
            }
           sum = squaresum(sum);
        }
        if(sum == 1)
        {
            return true;
        }
        return false;
    }
};