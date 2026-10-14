class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
             if(s[i] == '{' or s[i] == '(' or s[i] == '[')
             {
                st.push(s[i]);
             }
             else
             {
                if(st.size() and st.top() == '(' and s[i] == ')')
                {
                    st.pop();
                }
                else if(st.size() and st.top() == '{' and s[i] == '}')
                {
                    st.pop();
                }
                else if(st.size() and st.top() == '[' and s[i] == ']')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
             }
        }
        if(st.empty())
        {
            return true;
    
    }
    return false;
    }
};