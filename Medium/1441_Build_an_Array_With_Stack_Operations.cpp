#include<vector>
#include<stack>
#include<string>

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> ans;
        std::stack<int> s;
        int p = 0;
        int elm = 1;
        while(p < target.size()){
            if(target[p] != elm){
                ans.push_back("Push");
                ans.push_back("Pop");
            }else{
                ans.push_back("Push");
                p++;
            }
            elm++;
        }

        return ans;
    }
};