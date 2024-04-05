#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> a;
        std::unordered_map<char, char> b;
        for(int i = 0; i < s.size(); i++){
            if(a.find(s[i]) != a.end()){
                if(a[s[i]] != t[i])
                    return false;
            }
            if(b.find(t[i]) != b.end()){
                if(b[t[i]] != s[i])
                    return false;
            }
            b[t[i]] = s[i];
            a[s[i]] = t[i];
        }

        return true;
    }
};