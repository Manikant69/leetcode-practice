class Solution {
public:
    string removeKdigits(string num, int k) {

    if(num.length() <= k){
        return "0";
    }

    if(k == 0){
        return num;
    }

    stack<char> st;

    st.push(num[0]);

    for(int i=1; i<num.length(); i++){
        while( k > 0 && !st.empty() && st.top() > num[i]){
            st.pop();
            k--;
        }
        if(st.empty() && num[i] == '0')
            continue;

        st.push(num[i]);
    } 

      string ans;

    while(!st.empty()){
    if(k > 0){
        st.pop();
        k--;
        continue;
    }
    ans += st.top();
    st.pop();
    } 

    reverse(ans.begin(), ans.end());
    if(ans.length() == 0){
        ans += '0';
    }

      return ans;
    }
};
