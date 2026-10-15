class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        stack<int> sta;
        int k = 0;
        for(int i = 0; i < s.size(); i++){
             k++;
             if(s[i] == '(')
             {
                st.push(s[i]);
               
                sta.push(k);
                
             }
             else if(s[i] == ')')
             {
                if(st.size() and st.top() == '(' and s[i] == ')')
                {   
                    st.pop();
                    
                    sta.pop();
                }
                else
                {   
                    st.push(s[i]);
                    sta.push(k);
                }
             }
             
        }
        
        
          while(!sta.empty())
          { 
            s.erase(sta.top() - 1,1);
            sta.pop();
           
          }
             return s;

    }
};