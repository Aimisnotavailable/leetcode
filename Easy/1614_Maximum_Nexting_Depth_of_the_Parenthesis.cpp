#include <string>
#include <algorithm>

class Solution {
public:
    int maxDepth(std::string s) {
        int current_depth = 0;
        int max_depth = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                current_depth++;
            else if(s[i] == ')')
                current_depth--;
            max_depth = std::max(max_depth, current_depth);
        }
        return max_depth;
    }
};