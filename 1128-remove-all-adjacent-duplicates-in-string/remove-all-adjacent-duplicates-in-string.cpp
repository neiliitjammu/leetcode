class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0;
        while(i < s.size())
        {
            if(!st.empty() and s[i] == st.top())
            {
                st.pop();
                i++;
            }
            else
            {
                st.push(s[i]);
                i++;
            }
        }
        string ans = "";
        stack<char> helper;
        while(!st.empty())
        {
            helper.push(st.top());
            st.pop();
        }
        while(!helper.empty())
        {
            st.push(helper.top());
            ans += string(1,helper.top());
            helper.pop();
        }

        return ans;
    }
};