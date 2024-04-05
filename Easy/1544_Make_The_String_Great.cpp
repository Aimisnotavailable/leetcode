#include <stack>
#include <string>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::stack<char> st;
        for(char c : s){
            if(!st.empty() && std::abs(c - st.top()) == 32){
                st.pop();
            }else{
                st.push(c);
            }
        }

        std::string result;

        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};