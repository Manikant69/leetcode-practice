class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open, star;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{ //s[i] == '*'

                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{   // can't be balanced because there is no any star or open braces in left hand side 
                    return false;
                }
            }
        }


        while(!open.empty()){

            if(star.empty()){//there is no any star to make them closing braces.
                return false;
            }

            if(open.top() < star.top()){
                open.pop();
                star.pop();
            }
            else{   // if convert the * into closing braces even though it can't become a valid parenthesis -> because open bracket is lying in after the star -> * ( -> )(
                return false; 
            }
        }

        return true;

    }
};
