class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student;
        stack<int> sandwich;
        for(int i = sandwiches.size() - 1; i >= 0; i--)
        {
            sandwich.push(sandwiches[i]);
        }
        for(int i = 0; i < students.size(); i++)
        {
            student.push(students[i]);
        }
        int a = 0;
        while(!(student.empty() or sandwich.empty()) and a <= student.size())
        {
            if(sandwich.top() == student.front())
            {
                sandwich.pop();
                student.pop();
                a = 0;
            }
            else
            {
                student.push(student.front());
                student.pop();
                a++;
            }
        }
        return student.size();
        
    }
};