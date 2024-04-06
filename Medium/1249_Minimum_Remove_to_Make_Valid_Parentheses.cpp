#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        int oc = 0;
        int cc = 0;
        std::stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' ){
                oc++;
            }else if(s[i] == ')'){
                if(oc == 0)
                    continue;
                oc--;
            }
            st.push(s[i]);
        }
        
        std::string result = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if( c == ')'){
                cc++;
            }else if(c == '('){
                if(cc == 0){
                    continue;
                }
                cc--;
            }
            result += c; 
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};