#include <string>
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int x1 = 0, n1 = version1.size();
        int x2 = 0, n2 = version2.size();
        int i = 0, j = 0;
        
        while(i < n1 || j < n2){
            while(i < n1 && version1[i] != '.'){
                x1 = 10*x1 + (version1[i++] - '0');
            }

            while(j < n2 && version2[j] != '.'){
                x2 = 10*x2 + (version2[j++] - '0');
            }

            if(x1 < x2) return -1;
            else if(x1 > x2) return 1;
            i++;
            j++;
            x1 = 0;
            x2 = 0;
        }
        return 0;
    }
};
