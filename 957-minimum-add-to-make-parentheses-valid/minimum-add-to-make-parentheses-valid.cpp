class Solution {
public:
    int minAddToMakeValid(string s) {
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
            return 0;
    
    }
   int num = 0;
   while(!st.empty())
   {
    num++;
    st.pop();
   }
   return num;
    }
    };
