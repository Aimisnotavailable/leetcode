#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int g_l = 0;
        int g_r = 0;
        int a = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                if(g_l > 0)
                    g_l--;
                else if(a > 0)
                    a--;
                else
                    return false;
            }else if(s[i] == '('){
                g_l++;
            }else{
                a++;
            }
        }
        a = 0;
        for(int i = s.length() - 1; i >= 0 ; i--){
            if(s[i] == '('){
                if(g_r > 0)
                    g_r--;
                else if(a > 0)
                    a--;
                else
                    return false;
            }else if(s[i] == ')'){
                g_r++;
            }else{
                a++;
            }
            
        }

        return (g_l >= 0 || g_r >= 0);
    }
};