#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char,int> a;
        int n = s.length();
        int ans = 0;
        int l = 0;
        int r = 0;

        while(l < n && r < n){
            a[s[r]]++;
            while(a[s[r]] > 1){
                a[s[l]]--;
                l++;
            }
            ans = std::max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};