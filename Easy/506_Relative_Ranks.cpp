#include<vector>
#include<string>
#include<unordered_map>
class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<int> c(score.size());
        std::copy(score.begin(), score.end(), c.begin());
        
        std::sort(score.begin(), score.end(), [](int a, int b){
            return a > b;
        });
        
        std::unordered_map<int, int> a;
         
        
        for(int i = 0; i < score.size(); i++){
            a[score[i]] = i;
        }
        
        std::vector<std::string> b;
        for(int i = 0; i < c.size(); i++){
            if(a[c[i]] == 0)
                b.push_back("Gold Medal");
            else if(a[c[i]] == 1)
                b.push_back("Silver Medal");
            else if(a[c[i]] == 2)
                b.push_back("Bronze Medal");
            else
                b.push_back(to_string(a[c[i]]+1));
        }
            
        return b;
    }
};
