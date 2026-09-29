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
        int slow = n;
        int fast = n;
        if(slow == 1)
        {
            return true;
        }
        while(slow != 1)
        {   
            slow = squaresum(slow);
            fast = squaresum(squaresum(fast));
            if(slow == fast and slow != 1 and fast != 1)
            {
                return false;
            }
        }
        if(slow == 1)
        {
            return true;
        }
        return false;
    }
};