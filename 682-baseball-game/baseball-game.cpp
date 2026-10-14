class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;
        stack<int> helper;
        for(string i : operations){
            if(i == "+")
            {
               helper.push(score.top());
              int a = score.top();
               score.pop();
               helper.push(score.top());
              int b = score.top();
               score.pop();
               
               score.push(helper.top());
               helper.pop();
               score.push(helper.top());
               helper.pop();
               score.push(a + b);
            }
            else if(i == "D")
            {
               score.push(2 * score.top());

            }
            else if(i == "C")
            {
               score.pop();

            }
            else
            {
                score.push(stoi(i));
            }
        }
        int sum = 0;
        while(!score.empty())
        {
            sum += score.top();
            score.pop();
        }
        return sum;
    }
};