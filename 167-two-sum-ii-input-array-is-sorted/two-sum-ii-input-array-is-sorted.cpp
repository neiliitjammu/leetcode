class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> neil;
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j)
        {
          if(numbers[i] + numbers[j] == target)
          {
             neil.push_back(i + 1);
             neil.push_back(j + 1);
             return neil;
          }
          else if(numbers[i] + numbers[j] > target)
          {
            j--;
          }
          else
          {
            i++;
          }
        }
        return neil;
    }
};