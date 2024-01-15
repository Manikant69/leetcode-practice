class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;

        string ans = "";

        for(int i=0; i<s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i] == ')')
                {
                    st.pop();
                    if(!st.empty())
                    {
                        ans += ')';
                    }
                }
                else
                {
                    ans += s[i];
                    st.push(s[i]);
                }
            }
        }

        return ans;

    }
};
