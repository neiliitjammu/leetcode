class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        string ans = "";
        string p = "";
        
        for(int i = 0; i < s.size(); i++){
             if(s[i] == '{' or s[i] == '(' or s[i] == '[')
             {
                st.push(s[i]);
                p += string(1, s[i]);
             }
             else
             {  
                if(st.size() and st.top() == '(' and s[i] == ')')
                {
                    st.pop();
                    p += string(1, s[i]);
                }
                else if(st.size() and st.top() == '{' and s[i] == '}')
                {
                    st.pop();
                    p += string(1, s[i]);
                }
                else if(st.size() and st.top() == '[' and s[i] == ']')
                {
                    st.pop();
                    p += string(1, s[i]);
                }
                else
                {
                    st.push(s[i]);
                    p += string(1, s[i]);
                }


             }

             if(st.empty())
        {
            if(p.size() > 0)
            {
                p.erase(0,1);
                p.erase(p.size()-1,1);
                ans += p;
                p = "";
            }
    
         }
        }

        return ans;
        
    }
};