class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<int> st;
        vector<bool> v(s.length(), false);

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')')
            {
                if(!st.empty()){
                    int index = st.top();
                    st.pop();
                    v[index] = true;
                    v[i] = true;
                }
            }
            else{
                v[i] = true;
            }
        }

        for(int i=0; i<s.length(); i++)
        {
            if(v[i] == true){
                ans += s[i];
            }
        }

        return ans;
    }
};
