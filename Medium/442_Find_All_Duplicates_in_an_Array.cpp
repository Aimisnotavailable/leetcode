#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> a;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(i+1 < nums.size()){
                if(nums[i] == nums[i+1]){
                    i = i+1;
                    a.push_back(nums[i]);       
                }
            }
        }
        return a;
    }
};